#include "player.h"
#include <iostream>

Player::Player()
{
	if (!texture.loadFromFile("assets/player.png"))
	{
		std::cout << "Player texture improperly loaded..." << std::endl;
	}
	texture.setSmooth(false);

	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(8.f, 8.f));
	sprite.setScale(sf::Vector2f(2.f, 2.f));
	
	sprite.setPosition(sf::Vector2f(200.f, 200.f));
	boundingBox = sprite.getGlobalBounds();
	speed = 4;
	dir = Facing::UP;

	weapon = nullptr;
	isAttacking = false;
	

}

Player::~Player()
{
	delete weapon;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0, -speed));
		dir = Facing::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(0, speed));
		dir = Facing::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(-speed, 0));
		dir = Facing::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pos = sprite.getPosition();
		sprite.setPosition(pos + sf::Vector2f(speed, 0));
		dir = Facing::RIGHT;
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

void Player::equipWeapon()
{
	weapon = new Weapon((int)dir, pos.x, pos.y);
}

void Player::unequipWeapon()
{
	delete weapon;
	weapon = nullptr;
}



