#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "player.h"
#include "wall.h"

class Game
{
private:

	sf::VideoMode videoMode;
	sf::RenderWindow* window = nullptr;
	sf::Event event;
	sf::Music music;

	Player player;
	Wall* walls[56];
	
public:

	Game();
	~Game();

	bool isRunning() const;

	void update();
	void render();
};

#endif //GAME_H