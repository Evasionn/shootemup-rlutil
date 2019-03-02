#include "Obstacle.h"



Obstacle::Obstacle(int x, int y)
{
	//initialize obstacle's properties 
	x_pos = x; // x position
	y_pos = y; // y position
	object_char = 'X'; // character that will be printed for an obstacle
	object_color = 8; // Gray
	able_to_fire = false; // cannot fire bullet
	health_point = 60; // remaining health point
	movement_time = 500; // move every 0.5 second
	point = 250; // point that player will earn
}


Obstacle::~Obstacle()
{
}
