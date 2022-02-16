#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "player.h"
#include "wall.h"

#include <thread>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window = nullptr;

	sf::Event event;

	sf::Music music;

	Player player;

	
	Wall* walls[56];

	bool isColliding; // Move to player class
	

public:
	Game();
	~Game();

	const bool isRunning() const;
	void update();
	void render();
	void isAttackTime();
	
};

#endif