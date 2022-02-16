#include "player.h"
#include <iostream>

Player::Player()
{
	if (!texture.loadFromFile("assets/player.png"))
	{
		std::cout << "Player texture improperly loaded..." << std::endl;
	}
	sprite.setTexture(texture);
	texture.setSmooth(false);
	sprite.setOrigin(sf::Vector2f(8.f, 8.f));
	sprite.setScale(sf::Vector2f(4.f, 4.f));
	
	sprite.setPosition(sf::Vector2f(200.f, 200.f));
	boundingBox = sprite.getGlobalBounds();
	speed = 4;
	dir = Facing::UP;
	

}

Player::~Player()
{

}

/*
sf::RectangleShape Player::getPlayerSprite() const
{
	return pSprite;
}
*/

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



