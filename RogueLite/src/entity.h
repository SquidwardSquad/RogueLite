#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
protected:

	bool isColliding;
	
	sf::Texture texture;
	sf::Vector2f pos;

public:

	sf::Sprite sprite;
	sf::FloatRect collisionBox;

	Entity();
	virtual ~Entity();

	bool checkIfColliding() const;
	sf::Vector2f getPos();
};

#endif //ENTITY_H
