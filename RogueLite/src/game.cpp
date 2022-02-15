#include "game.h"

#include <iostream>

Game::Game():
    event(), //So visual studio can stop being pissy
    player()
{
    
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "RogueLite", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);

    int j = 0;
    for (int i = 50; i < 800; i += 100)
    {
        Wall* temp = new Wall(i, 50.f);
        walls[j++] = temp;
    }

    isColliding = false;
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
			{
				window->close();
			}
            break;

        }
    }

	player.boundingBox = player.getPlayerSprite().getGlobalBounds();
    for (int i = 0; i < 8; i++)
    {
        if (player.boundingBox.intersects(walls[i]->collisionBox))
        {
            switch (player.dir)
            {
            case Player::Facing::UP:
                player.pSprite.move(sf::Vector2f(0, 4));
                break;

            case Player::Facing::DOWN:
                player.pSprite.move(sf::Vector2f(0, -4));
                break;

            case Player::Facing::LEFT:
                player.pSprite.move(sf::Vector2f(4, 0));
                break;

            case Player::Facing::RIGHT:
                player.pSprite.move(sf::Vector2f(-4, 0));
                break;
            }
            isColliding = true;
        }
        
    }

    if (!isColliding)
    {
        player.move();
    }
    isColliding = false;
	
}
void Game::render()
{
    window->clear(sf::Color(0, 0, 0));

    //Draw objects here
	
    for (int i = 0; i < 8; i++)
    {
        window->draw(walls[i]->sprite);
    }



    window->draw(player.getPlayerSprite());

    

    window->display();
}