#include "Ship.h"



Ship::Ship()
{
	health_point = 100;
	x_pos = rlutil::tcols() / 2;
	y_pos = rlutil::trows();
}

Ship::Ship(int offset) {
	health_point = 100;
	x_pos = (rlutil::tcols() - offset) / 2;
	y_pos = rlutil::trows();
}

Ship::~Ship()
{
	eraseShip();
}

void Ship::drawShip() {
	gotoxy(x_pos, y_pos);
	rlutil::setColor(ship_color);
	cout << ship_char;
}

void Ship::eraseShip() {
	gotoxy(x_pos, y_pos);
	cout << " ";
}

void Ship::move(int key, int offset) {
	eraseShip(); // erase ship
	// change position according to the key input
	if (key == rlutil::KEY_LEFT || key == 'a' || key == 'A') x_pos--;
	else if (key == rlutil::KEY_RIGHT || key == 'd' || key == 'D') x_pos++;
	else if (key == rlutil::KEY_UP || key == 'w' || key == 'W') y_pos--;
	else if (key == rlutil::KEY_DOWN || key == 's' || key == 'S') y_pos++;
	

	// movement validation
	if (x_pos < 1) x_pos = 1;
	if (x_pos > rlutil::tcols() - offset - 1) x_pos = rlutil::tcols() - offset - 1;
	if (y_pos < 1) y_pos = 1;
	if (y_pos > rlutil::trows()) y_pos = rlutil::trows();


	drawShip(); // re-draw the main ship
}

void Ship::setPosition(int x, int y) {
	x_pos = x;
	y_pos = y;
}

int Ship::getX() {
	return x_pos;
}

int Ship::getY() {
	return y_pos;
}

int Ship::getHP() {
	return health_point;
}

void Ship::setHP(int hp) {
	health_point = hp;
}

void Ship::fire(vector<Bullet*> & bullets) {
	bullets.push_back(new Bullet(x_pos, y_pos, true)); // just addes bullet to the game area
}

void Ship::takeDamage(int damage) {
	health_point -= damage;
	if (health_point < 0) health_point = 0;
}
bool Ship::isDeath() {
	return health_point == 0;
}