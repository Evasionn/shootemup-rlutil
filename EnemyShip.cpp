#include "EnemyShip.h"



EnemyShip::EnemyShip(int x, int y)
{
	//initialize enemy ship's properties 
	x_pos = x; // x position
	y_pos = y; // y position
	object_char = 'Y'; // character that will be printed for a enemy ship
	object_color = 12; // Light Red
	able_to_fire = true; // can fire bullet
	health_point = 10; // remaining health point
	movement_time = 1000; // move every second
	fire_rate = 2500; // fires bullet every 2.5 seconds 
	point = 50; // point that player will earn
}


EnemyShip::~EnemyShip()
{
}
