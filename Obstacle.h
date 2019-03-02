#pragma once
#include "EnemyObject.h"
class Obstacle :
	public EnemyObject
{
public:
	Obstacle(int x, int y);
	~Obstacle();
};

