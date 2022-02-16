#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player
{
private:
	
	bool isColliding = false;
	sf::Texture texture;
	
	int speed;
public:
	Player();
	~Player();


	sf::Sprite sprite;
	sf::FloatRect boundingBox;

	sf::Vector2f pos;

	enum class Facing
	{
		UP = 0,
		LEFT,
		RIGHT,
		DOWN
	};

	

	Facing dir;


	//sf::RectangleShape getPlayerSprite() const;
	void move();

};

#endif