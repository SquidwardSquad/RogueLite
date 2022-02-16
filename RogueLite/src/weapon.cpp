#include "weapon.h"

#include <iostream>

Weapon::Weapon(int playerDir, float playerX, float playerY)
{
	if (!texture.loadFromFile("assets/sword.png"))
	{
		std::cout << "Sword texture improperly loaded..." << std::endl;
	}
	texture.setSmooth(false);

	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(2.f, 4.f));
	sprite.setOrigin(sf::Vector2f(4.f, 4.f));

	switch (playerDir)
	{
	case 0: //Up
		
		sprite.setPosition(sf::Vector2f(playerX, playerY - 24));
		
		break;

	case 3: //Down

		sprite.setPosition(sf::Vector2f(playerX, playerY + 24));
		sprite.setRotation(180);
		break;

	case 1: //Left

		sprite.setPosition(sf::Vector2f(playerX - 24, playerY));
		sprite.setRotation(270);
		break;

	case 2: //Right

		sprite.setPosition(sf::Vector2f(playerX + 24, playerY));
		sprite.setRotation(90);
		break;
	}

	collisionBox = sprite.getGlobalBounds();
	speed = 4;
}

Weapon::~Weapon()
{

}

