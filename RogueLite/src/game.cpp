#include "game.h"

Game::Game():
    event(), //So visual studio can stop being pissy
    player()
{
    
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "RogueLite", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
}

Game::~Game()
{
	delete window;
}

const bool Game::isRunning() const
{
	return window->isOpen();
}

void Game::update()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;

        }
    }
}
void Game::render()
{
    window->clear(sf::Color(0, 0, 0));

    //Draw objects here
    window->draw(player.getPlayerSprite());

    window->display();
}