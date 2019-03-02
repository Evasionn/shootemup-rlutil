#pragma once
#include "rlutil.h"
#include "Bullet.h"
#include <vector>
#include <ctime>

using namespace std;
class EnemyObject
{
public:
	EnemyObject();
	~EnemyObject();

	void drawObject(); // draws enemy object
	void move(); // automatic movement of the object

	void fire(vector<Bullet *> & bullets); // automatic fire ability of armed enemies
	bool checkHitWall(); // checks the enemy touches the screen
	void takeDamage(int damage); // taking damage
	bool isDeath(); // telling the object is death or not

	// Getters and setters
	int getX(); // return x_pos
	int getY(); // return y_pos
	void setPosition(int x, int y); // sets x_pos and y_pos
	int getHP(); // return health_point
	void setHP(int hp); // sets health_point
	bool getFireAbility(); // return able_to_fire
	void setFireAbility(bool ability); // sets able_to_fire
	void setChar(char character); // sets character of the enemy
	void setColor(int color); // sets color of the enemy
	int getPoint(); // get point that player will earn if he/she kills the enemy
	void setMovementTime(int seconds);  // sets movement time for the automatic move
protected:
	int fire_rate; // stores the fire rate in miliseconds
	int x_pos; // x position
	int y_pos; // y position
	int health_point; // HP of the object
	bool able_to_fire; // ability to fire
	char object_char; // character that will be printed while enemy is called
	int object_color; // color of the enemy
	int movement_time; // stores movement time in miliseconds
	int point; // point that player will earn after the object is killed
private:
	clock_t last_movement; // stores last movement time
	clock_t last_fire; // stores last fire time
	void eraseObject(); // erases object on the game board
	
};

