#ifndef GAME_H
#define GAME_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "player.h"
#include "wall.h"
#include "enemy.h"

class Game
{
private:

	sf::VideoMode videoMode;
	
	sf::Event event;
	sf::Music music;

	Player player;
	Wall* walls[56];
	Enemy* enemies[5];

	double diffScale;
	
public:

	sf::RenderWindow* window = nullptr;

	Game();
	~Game();

	bool isRunning() const;

	void update();
	void render();
};

#endif //GAME_H