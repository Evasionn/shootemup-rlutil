#include "EnemyObject.h"



EnemyObject::EnemyObject()
{
	// setting timers
	last_movement = clock();
	last_fire = clock();
}


EnemyObject::~EnemyObject()
{
	eraseObject();
}

int EnemyObject::getX() {
	return x_pos;
}

int EnemyObject::getY() {
	return y_pos;
}

int EnemyObject::getHP() {
	return health_point;
}

void EnemyObject::setPosition(int x, int y) {
	x_pos = x;
	y_pos = y;
}

void EnemyObject::setHP(int hp) {
	health_point = hp;
}

bool EnemyObject::getFireAbility() {
	return able_to_fire;
}

void EnemyObject::setFireAbility(bool ability) {
	able_to_fire = ability;
}

void EnemyObject::eraseObject() {
	gotoxy(x_pos, y_pos);
	cout << " ";
}

void EnemyObject::setChar(char character) {
	object_char = character;
}

void EnemyObject::setColor(int color) {
	object_color = color;
}

void EnemyObject::drawObject() {
	gotoxy(x_pos, y_pos);
	rlutil::setColor(object_color);
	cout << object_char;
}
void EnemyObject::move() {
	double elapsed_time = double(clock() - last_movement);
	if (elapsed_time < movement_time) return;
	
	last_movement = clock(); // sets clock for the next round
	eraseObject(); // erase the object
	y_pos++; // go down
	drawObject(); // and re-draw again
}

void EnemyObject::setMovementTime(int miliseconds) {
	movement_time = miliseconds;
}

void EnemyObject::fire(vector<Bullet *> & bullets) {
	if (!able_to_fire) return;
	double elapsed_time = double(clock() - last_fire);
	if (elapsed_time < fire_rate) return;

	last_fire = clock(); // sets clock for the next round
	bullets.push_back(new Bullet(x_pos, y_pos, false)); // fire a bullet
}

bool EnemyObject::checkHitWall() {
	if (y_pos < rlutil::trows()) return false;
	return true;
}

void EnemyObject::takeDamage(int damage) {
	health_point -= damage;
	if (health_point < 0) health_point = 0;
}

bool EnemyObject::isDeath() {
	return health_point == 0;
}

int EnemyObject::getPoint() {
	return point;
}