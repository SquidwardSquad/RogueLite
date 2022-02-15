#include "player.h"

Player::Player()
{
	pSprite.setSize(sf::Vector2f(50.f, 50.f));
	pSprite.setFillColor(sf::Color::Cyan);
	pSprite.setOrigin(sf::Vector2f(25.f, 25.f));
	pSprite.setPosition(sf::Vector2f(400.f, 300.f));
	boundingBox = pSprite.getGlobalBounds();
	speed = 4;
	dir = Facing::UP;
	

}

Player::~Player()
{

}

sf::RectangleShape Player::getPlayerSprite() const
{
	return pSprite;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pos = pSprite.getPosition();
		pSprite.setPosition(pos + sf::Vector2f(0, -speed));
		dir = Facing::UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pos = pSprite.getPosition();
		pSprite.setPosition(pos + sf::Vector2f(0, speed));
		dir = Facing::DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		pos = pSprite.getPosition();
		pSprite.setPosition(pos + sf::Vector2f(-speed, 0));
		dir = Facing::LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pos = pSprite.getPosition();
		pSprite.setPosition(pos + sf::Vector2f(speed, 0));
		dir = Facing::RIGHT;
	}
	
}



