#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Entity
{
protected:

	sf::Texture texture;


	sf::Vector2f pos;


public:

	Entity();
	virtual ~Entity();

	sf::Sprite sprite;
	sf::FloatRect collisionBox;



};


#endif  //ENTITY_H
