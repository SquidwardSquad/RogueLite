#include "entity.h"

#include <iostream>

Entity::Entity()
{	 
	isColliding = false;
}

Entity::~Entity()
{
}

bool Entity::checkIfColliding() const
{
	return isColliding;
}

sf::Vector2f Entity::getPos()
{
	return pos;
}
