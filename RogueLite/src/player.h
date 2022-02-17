#ifndef PLAYER_H
#define PLAYER_H

//Inherited Class
#include "entity.h"

#include "weapon.h"

class Player : public Entity
{
private:
	
	float speed;
	bool isAttacking;

	void equipWeapon();
	void unequipWeapon();

public:

	enum class Facing
	{
		UP = 0,
		LEFT,
		RIGHT,
		DOWN
	};

	Facing dir;
	
	Weapon* weapon;

	Player();
	~Player();

	bool checkIfAttacking() const;
	void alterCollision(bool isColliding);

	void move();
	void attack();
};

#endif //PLAYER_H