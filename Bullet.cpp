#include "Bullet.h"



Bullet::Bullet(int x, int y, bool is_mine)
{
	friendly = is_mine;
	x_pos = x;
	if (is_mine)
		y_pos = y - 1; // starts to go one row above from the object
	else
		y_pos = y + 1; // starts to go one row below from the object
}


Bullet::~Bullet()
{
	eraseBullet();
}

void Bullet::drawBullet() {
	gotoxy(x_pos, y_pos);
	rlutil::setColor(bullet_color);
	cout << bullet_char;
}

void Bullet::eraseBullet() {
	gotoxy(x_pos, y_pos);
	cout << " "; // just printing empty column bullet's cordinate
}
void Bullet::move() {
	eraseBullet();
	if (friendly) y_pos--; // go up if the bullet is fired by the player
	else y_pos++; // otherwise go down
	drawBullet(); // draws bullet
}

int Bullet::getX() {
	return x_pos;
}

int Bullet::getY() {
	return y_pos;
}

void Bullet::setPosition(int x, int y) {
	x_pos = x;
	y_pos = y;
}

bool Bullet::isFriendly() {
	return friendly;
}

bool Bullet::checkHitWall() {
	// checking bullet that is going up
	if (friendly) {
		if (y_pos > 1) return false;
		else return true;
	}
	else{
		// checking the bullet that is going down
		if (y_pos < rlutil::trows()) return false;
		else return true;
	}
}

int Bullet::getDamage() {
	return damage;
}

bool Bullet::checkHitObject(int x, int y) {
	if (x_pos == x && y_pos == y) return true; // if the bullet location matches with the object's location
	return false;
}