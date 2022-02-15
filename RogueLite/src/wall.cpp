#include "wall.h"

Wall::Wall()
{
	wSprite.setSize(sf::Vector2f(100.f, 100.f));
	wSprite.setFillColor(sf::Color::Red);
	wSprite.setOrigin(sf::Vector2f(50.f, 50.f));
	wSprite.setPosition(sf::Vector2f(50.f, 50.f));
	boundingBox = wSprite.getGlobalBounds();

}

Wall::~Wall()
{

}

sf::RectangleShape Wall::getWallSprite() const
{
	return wSprite;
}
