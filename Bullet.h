#pragma once
#include "rlutil.h"

using namespace std;
class Bullet
{
public:
	Bullet(int x, int y, bool is_mine); 
	~Bullet();


	void drawBullet(); // draws bullet to the game area
	void move(); // movement of the bullet
	bool isFriendly(); // return friendly to determine bullet is fired from player's ship or enemy's ship
	bool checkHitWall(); // checks the bullet hit to the game walls
	bool checkHitObject(int x, int y); // check the bullet hit an enemy object or player's ship

	// Getters and setters
	int getX(); // returns x_pos
	int getY(); // returns y_pos
	void setPosition(int x, int y); // sets x_pos and y_pos
	int getDamage(); // returns bullet's damage that will object take

private:
	int x_pos; // x position
	int y_pos; // y position
	bool friendly; // stores the information of object that fires
	const int damage = 10; // cause damage point
	const char bullet_char = char(248); // character that will be printed for a bullet
	const int bullet_color = 14; // Light yellow
	void eraseBullet(); // erases bullet from the game area
	
};

