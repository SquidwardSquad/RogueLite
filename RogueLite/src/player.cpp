#include "player.h"

Player::Player()
{
	pSprite.setSize(sf::Vector2f(50.f, 50.f));
	pSprite.setFillColor(sf::Color::Cyan);

}

Player::~Player()
{

}

sf::RectangleShape Player::getPlayerSprite() const
{
	return pSprite;
}