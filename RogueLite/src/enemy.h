#ifndef ENEMY_H
#define ENEMY_H

//Inherited Class
#include "entity.h"

class Enemy : public Entity
{
private:
	
	int moveType;

public:

	enum class Facing
	{
		UP = 0,
		LEFT,
		RIGHT,
		DOWN
	};

	float speed;
	bool collision;
	bool isAlive;

	Facing dir;

	Enemy(float xPos, float yPos, double difScale = 1);
	~Enemy();

	void move();
	void oppMove();
};

#endif //ENEMY_H