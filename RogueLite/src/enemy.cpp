#include "enemy.h"

#include <iostream>
#include <cstdlib>

Enemy::Enemy(float xPos, float yPos, double difScale)
{
	//Texture Init
	if (!texture.loadFromFile("assets/enemy.png"))
	{
		std::cout << "Enemy texture improperly loaded..." << std::endl;
	}
	texture.setSmooth(false);

	//Sprite Init
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(8.f, 8.f));
	sprite.setScale(sf::Vector2f(2.f, 2.f));
	sprite.setPosition(sf::Vector2f(xPos, yPos));
	collisionBox = sprite.getGlobalBounds();

	speed = (float)(4.f * difScale);

	std::srand(time(0));

	collision = false;
	isAlive = true;
}

Enemy::~Enemy()
{
}

void Enemy::move()
{ 
	pos = sprite.getPosition();
	sprite.setPosition(pos + sf::Vector2f(speed, 0.f));
}