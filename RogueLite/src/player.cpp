#include "player.h"

#include <iostream>

Player::Player()
{
	//Texture Init
	if (!texture.loadFromFile("assets/player.png"))
	{
		std::cout << "Player texture improperly loaded..." << std::endl;
	}
	texture.setSmooth(false);

	//Sprite Init
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(8.f, 8.f));
	sprite.setScale(sf::Vector2f(2.f, 2.f));
	sprite.setPosition(sf::Vector2f(400.f, 300.f));
	collisionBox = sprite.getGlobalBounds();

	speed = 4.f;
	isAttacking = false;

	dir = Facing::UP;

	weapon = nullptr;
}

Player::~Player()
{
	delete weapon;
}

void Player::equipWeapon()
{
	weapon = new Weapon((int)dir, pos.x, pos.y);
}

void Player::unequipWeapon()
{
	delete weapon;
	weapon = nullptr;
}

bool Player::checkIfAttacking() const
{
	return isAttacking;
}

void Player::alterCollision(bool isColliding)
{
	this->isColliding = isColliding;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0.f, -speed));
		dir = Facing::UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(-speed, 0.f));
		dir = Facing::LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(speed, 0.f));
		dir = Facing::RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0.f, speed));
		dir = Facing::DOWN;
	}
}

void Player::attack()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		equipWeapon();
		isAttacking = true;
	}
	else
	{
		isAttacking = false;
		unequipWeapon();
	}
}