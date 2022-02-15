#include "entity.h"

Entity::Entity()
{
  sprite.setTexture(texture);
  sprite.setSize(sf::Vector2f(50.f, 50.f));
  sprite.setOrigin(sf::Vector2f(25.f, 25.f));
	sprite.setPosition(sf::Vector2f(400.f, 300.f));
	collisionBox = sprite.getGlobalBounds();

  
}

Entity::~Entity()
{
  
}
