#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Entity
{
private:

sf::Texture texture;
/*
if (!texture.loadFromFile("image.png"))
{
    
}
*/

sf::Vector2f pos;


public:

Entity();
~Entity();

sf::Sprite sprite;
sf::FloatRect collisionBox;



};


#endif  //ENTITY_H
