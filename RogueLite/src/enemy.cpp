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

	//sprite.setColor(sf::Color((sf::Uint8)difScale * 5, (sf::Uint8)1, (sf::Uint8)1));

	speed = (float)(4.f * difScale);

	std::srand(time(0));
	moveType = (std::rand() % 4) + 1;

	collision = false;
	isAlive = true;
}

Enemy::~Enemy()
{
}

void Enemy::move()
{ 
	switch (moveType)
	{
	case 1:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0.f, -speed));
		dir = Facing::UP;
		break;

	case 2:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0.f, speed));
		dir = Facing::DOWN;
		break;

	case 3:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(-speed, 0.f));
		dir = Facing::LEFT;
		break;

	case 4:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(speed, 0.f));
		dir = Facing::RIGHT;
		break;
	}
}

void Enemy::oppMove()
{
	switch (moveType)
	{
	case 1:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0.f, speed));
		dir = Facing::UP;
		break;

	case 2:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0.f, -speed));
		dir = Facing::DOWN;
		break;

	case 3:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(speed, 0.f));
		dir = Facing::LEFT;
		break;

	case 4:
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(-speed, 0.f));
		dir = Facing::RIGHT;
		break;
	}
}