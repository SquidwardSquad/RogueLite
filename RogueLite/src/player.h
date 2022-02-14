#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
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

	sf::RectangleShape pSprite;
	
public:
	Player();
	~Player();

	sf::RectangleShape getPlayerSprite() const;

};

#endif