#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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

	

	
	bool isColliding = false;

	


	
public:
	Player();
	~Player();


	sf::RectangleShape pSprite;
	const int maxVel = 4;
	sf::FloatRect boundingBox;

	sf::Vector2f pos;

	enum class Facing
	{
		UP = 0,
		LEFT,
		RIGHT,
		DOWN
	};

	int speed;

	Facing dir;


	sf::RectangleShape getPlayerSprite() const;
	void move();

};

#endif