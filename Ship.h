#pragma once
#include "rlutil.h"
#include "Bullet.h"
#include <vector>

using namespace std;
class Ship
{
public:
	Ship();
	Ship(int offset);
	~Ship();


	void drawShip(); // draws main ship on game area
	void move(int key, int offset = 0); // movement of the player
	void fire(vector<Bullet *> & bullets); // firing bullet
	void takeDamage(int damage);  // taking damage 
	bool isDeath(); // tells if the player is death or not


	// Getters and setters
	int getX(); // returns x_pos
	int getY(); // returns y_pos
	void setPosition(int x, int y); // sets x_pos and y_pos
	int getHP(); // returns health_point
	void setHP(int hp); // sets health_point
private:
	int x_pos; // x position of the player
	int y_pos; // y position of the player
	int health_point; // remaining health point
	void eraseShip(); // erases main ship on the game area
	const char ship_char = 'M'; // character that will be printed when ship is drawn
	const int ship_color = 11; // Light blue 
};

