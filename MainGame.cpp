#include "MainGame.h"
#include "Menu.h"


MainGame::MainGame()
{
	rlutil::hidecursor(); // hiding cursor
	is_running = false;
	high_score = 0;
	current_score = 0;
	lives = 3;
	beforeGame();
}


MainGame::~MainGame()
{
	rlutil::resetColor();
	rlutil::cls();
}

void MainGame::beforeGame() {
	if (!is_running) {
		Menu * menu = new Menu();
		if (menu->callMenu()) {
			delete menu;
			gameLooper();
		}
		else {
			delete menu;
			exit(0);
		}
	}
}
void MainGame::newGame() {
	rlutil::resetColor();
	rlutil::cls();
	is_running = true;
	current_score = 0;
	lives = 3;
	player = new Ship(infoTableOffset);
	player->drawShip();
	player->setHP(100);

	drawInfoBoxes();
	enemies.clear();
	bullets.clear();
}

bool MainGame::isFinished() {
	return lives == 0;
}

void MainGame::gameOver() {
	// Saving high score
	if (high_score < current_score) high_score = current_score;

	is_running = false;
	rlutil::resetColor();
	rlutil::cls();
	string message = "Game is over!";
	gotoxy(rlutil::tcols() / 2 - message.length() / 2, rlutil::trows() / 2);
	rlutil::setColor(4);
	cout << message;
	message = "Press 'N' to start new game.";
	gotoxy(rlutil::tcols() / 2 - message.length() / 2, rlutil::trows() / 2 + 3);
	cout << message;

	char key = getch();
	if (key == 'n' || key == 'N') newGame();
}
void MainGame::refreshGame() {
	rlutil::resetColor();
	rlutil::cls();
	// if the game is finished call game over screen
	if (isFinished()) {
		gameOver();
		return;
	}
	is_running = true;

	player = new Ship(infoTableOffset);
	player->drawShip();
	player->setHP(100);

	drawInfoBoxes();
	enemies.clear();
	bullets.clear();
}

void MainGame::gameLooper() {
	refreshGame();
	while (is_running) {
		if (kbhit()) {
			int key = rlutil::getkey();

			if (key == rlutil::KEY_SPACE) {
				// fire bullet
				player->fire(bullets);
			}
			else player->move(key, infoTableOffset); // moves main ship
		}
		updateBullets(); // looper for the bullets
		updateEnemies(); // looper for the enemies
		addEnemy(); // automatically adds enemy
		// check if the player is death
		if (player->isDeath()) {
			lives--;
			refreshGame();
		}

		rlutil::msleep(30);
	}
	
	
}

void MainGame::updateBullets() {
	try {
		for (int i = 0; i < bullets.size(); i++) {
			// Checking if the bullet hits enemy
			if (bullets.at(i)->isFriendly()) {
				for (int j = 0; j < enemies.size(); j++) {
					if (bullets.at(i)->checkHitObject(enemies.at(j)->getX(), enemies.at(j)->getY())) {
						// enemy should take damage
						enemies.at(j)->takeDamage(bullets.at(i)->getDamage());

						// erasing bullet
						bullets.at(i)->~Bullet();
						bullets.erase(bullets.begin() + i);

						// checking if enemy is death
						if (enemies.at(j)->isDeath()) {
							// destroy the enemy and increase score
							current_score += enemies.at(j)->getPoint();
							drawInfoBoxes();
							enemies.at(j)->~EnemyObject();
							enemies.erase(enemies.begin() + j);
						}
						else enemies.at(j)->drawObject();
					}
				}
			}
			else {
				// Checking if the bullet hits the player
				if (bullets.at(i)->checkHitObject(player->getX(), player->getY())) {
					// player should take damage
					player->takeDamage(bullets.at(i)->getDamage());
					
					// erasing bullet
					bullets.at(i)->~Bullet();
					bullets.erase(bullets.begin() + i);

					// re-draw player's ship
					player->drawShip();

					drawInfoBoxes();
				}
			}


			// Checking wall hit of bullets
			if (!bullets.at(i)->checkHitWall()) {
				bullets.at(i)->move();
			}
			else {
				bullets.at(i)->~Bullet();
				bullets.erase(bullets.begin() + i);
			}
		}
	}
	catch (const exception& e) {
		// nothing to do
	}

}

void MainGame::updateEnemies() {
	autoFire(); // automatic shoot with timer

	for (int i = 0; i < enemies.size(); i++) {
		// if not hitting the wall
		if (!enemies.at(i)->checkHitWall()) {
			enemies.at(i)->move(); // just move
		}
		else {
			//erase enemy
			enemies.at(i)->~EnemyObject();
			enemies.erase(enemies.begin() + i);
			
			// player takes damage
			player->takeDamage(20);
			drawInfoBoxes();
		}
	}
}

void MainGame::autoFire() {
	for (int i = 0; i < enemies.size(); i++) {
		enemies.at(i)->fire(bullets);
	}
}

void MainGame::addEnemy() {
	// adding enemy to the screen every 2 seconds
	double elapsed_time = double(clock() - enemy_cron);
	if (elapsed_time < 2000) return;

	enemy_cron = clock();
	int max = rlutil::tcols() - infoTableOffset - 1; // limits x position according to the screen offset
	srand(time(NULL));
	int type = (rand() % 10) + 1;
	int x = (rand() % max) + 1;
	if (type <= 9) enemies.push_back(new EnemyShip(x, 1)); // 90% - adds enemy ship
	else enemies.push_back(new Obstacle(x, 1)); // %10 - adds obstacle
}

void MainGame::drawInfoBoxes() {
	rlutil::setColor(15);
	// Horizontal lines
	gotoxy(rlutil::tcols() - infoTableOffset, 8);
	for (int i = rlutil::tcols() - infoTableOffset; i <= rlutil::tcols(); i++) cout << char(219);
	gotoxy(rlutil::tcols() - infoTableOffset, 16);
	for (int i = rlutil::tcols() - infoTableOffset; i <= rlutil::tcols(); i++) cout << char(219);
	gotoxy(rlutil::tcols() - infoTableOffset, 24);
	for (int i = rlutil::tcols() - infoTableOffset; i <= rlutil::tcols(); i++) cout << char(219);
	// Vertical Line
	for (int i = 0; i < rlutil::trows(); i++) {
		gotoxy(rlutil::tcols() - infoTableOffset, i + 1);
		cout << char(219);
	}

	string message = "Current Score: " + to_string(current_score);
	gotoxy(rlutil::tcols() - (infoTableOffset / 2) - message.length() / 2, 4);
	rlutil::setColor(9);
	cout << message;
	message = "High Score: " + to_string(high_score);
	gotoxy(rlutil::tcols() - (infoTableOffset / 2) - message.length() / 2, 12);
	rlutil::setColor(6);
	cout << message;
	message = "Lives: " + to_string(lives);
	gotoxy(rlutil::tcols() - (infoTableOffset / 2) - message.length() / 2, 20);
	rlutil::setColor(2);
	cout << message;
	message = "Health Point: " + to_string(player->getHP()) + " ";
	gotoxy(rlutil::tcols() - (infoTableOffset / 2) - message.length() / 2, 28);
	rlutil::setColor(4);
	cout << message;
}