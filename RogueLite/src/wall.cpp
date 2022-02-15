#include "wall.h"

#include <iostream>

Wall::Wall(float xPos, float yPos)
{
	if (!texture.loadFromFile("assets/wall.png"))
	{
		std::cout << "Wall texture improperly loaded..." << std::endl;
	}

	//DONT QUESTION THE STUPID SCALING
	sprite.setTexture(texture);
	sprite.setOrigin(sf::Vector2f(25.f, 25.f));
	sprite.setScale(sf::Vector2f(2.f, 2.f));
	sprite.setPosition(sf::Vector2f(xPos, yPos));
	collisionBox = sprite.getGlobalBounds();

}

Wall::~Wall()
{

}

