#ifndef ENEMY_H
#define ENEMY_H

//Inherited Class
#include "entity.h"

class Enemy : public Entity
{
private:

public:

	float speed;
	bool collision;
	bool isAlive;

	Enemy(float xPos, float yPos, double difScale = 1);
	~Enemy();

	void move();
};

#endif //ENEMY_H