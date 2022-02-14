#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "player.h"

class Game
{
private:
	sf::RenderWindow* window = nullptr;
	sf::VideoMode videoMode;
	sf::Event event;
	Player player;

public:
	Game();
	~Game();

	const bool isRunning() const;

	void update();
	void render();
};

#endif