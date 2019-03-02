#pragma once
#include "Ship.h"
#include "Bullet.h"
#include "EnemyShip.h"
#include "Obstacle.h"
#include <ctime>
#include <vector>
#include <cstdlib>
class MainGame
{
public:
	MainGame();
	~MainGame();

private:
	bool is_running; // status of the game process
	
	int high_score; // stores high score of the current season
	int current_score; // stores current score of the player 
	int lives; // left lives
	clock_t enemy_cron; // stores latest added enemy for the timer
	Ship * player; // main ship
	vector<Bullet *> bullets; // bullets on the game area
	vector<EnemyObject *> enemies; // enemies on the game area
	const int infoTableOffset = 45; // offset of the sidebar table


	void beforeGame(); // menu caller
	void gameLooper(); // main game looper
	void updateBullets(); // bullet looper
	void updateEnemies(); // enemy looper
	void drawInfoBoxes(); // side bar info table
	void autoFire(); // automatic shoot from enemies that has gun
	void addEnemy(); // automatically adds enemy to the game board
	void refreshGame(); // refresh game properties
	void gameOver(); // game over screen
	bool isFinished(); // checks the game is actually finished
	void newGame(); // creates new game
};

