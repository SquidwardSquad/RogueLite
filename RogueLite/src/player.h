#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "weapon.h"

class Player
{
private:
	
	bool isColliding = false;
	sf::Texture texture;
	
	int speed;

	void equipWeapon();
	void unequipWeapon();

public:
	Player();
	~Player();


	sf::Sprite sprite;
	sf::FloatRect boundingBox;
	sf::Vector2f pos;

	

	Weapon* weapon;

	enum class Facing
	{
		UP = 0,
		LEFT,
		RIGHT,
		DOWN
	};

	

	Facing dir;
	bool isAttacking;

	void move();
	void attack();
	
	

};

#endif