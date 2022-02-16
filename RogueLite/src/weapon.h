#ifndef WEAPON_H
#define WEAPON_H

#include "entity.h"

class Weapon : public Entity
{
private:
	int speed;
public:
	

	Weapon(int playerDir, float playerX, float playerY);
	~Weapon();

	

};

#endif

