#ifndef WEAPON_H
#define WEAPON_H

//Inherited Class
#include "entity.h"

class Weapon : public Entity
{
private:

	float speed;

public:
	
	Weapon(int playerDir, float playerX, float playerY);
	~Weapon();
};

#endif //WEAPON_H