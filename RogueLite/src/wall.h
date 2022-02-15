#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Wall
{



	
	private:
		/*
		sf::Texture texture;
		if (!texture.loadFromFile("image.png"), sf::IntRect(0, 0, 0, 0))
		{
			// error...
		}
		sf::Sprite sprite;
		sprite.setTexture(texture);
		*/

		sf::RectangleShape wSprite;

		bool isColliding = false;



	public:
		Wall();
		~Wall();

		
		sf::FloatRect boundingBox;

		sf::Vector2f pos;


		sf::RectangleShape getWallSprite() const;
		
};
#endif
