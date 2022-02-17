#include "weapon.h"

#include <iostream>

Weapon::Weapon(int playerDir, float playerX, float playerY)
{
	//Texture Init
	if (!texture.loadFromFile("assets/sword.png"))
	{
		std::cout << "Sword texture improperly loaded..." << std::endl;
	}
	texture.setSmooth(false);

	//Sprite Init
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(2.f, 4.f));
	sprite.setOrigin(sf::Vector2f(4.f, 4.f));
	switch (playerDir)
	{
	case 0: //Up
		
		sprite.setPosition(sf::Vector2f(playerX, playerY - 24.f));
		
		break;

	case 1: //Left

		sprite.setPosition(sf::Vector2f(playerX - 24.f, playerY));
		sprite.setRotation(270);
		break;

	case 2: //Right

		sprite.setPosition(sf::Vector2f(playerX + 24.f, playerY));
		sprite.setRotation(90);
		break;

	case 3: //Down

		sprite.setPosition(sf::Vector2f(playerX, playerY + 24.f));
		sprite.setRotation(180);
		break;
	}
	collisionBox = sprite.getGlobalBounds();

	speed = 4.f;
}

Weapon::~Weapon()
{
}

