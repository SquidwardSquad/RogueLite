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

    //top row
    int j = 0;
    for (int i = 25; i < 800; i += 50)
    {
        Wall* temp = new Wall(i, 25.f);
        walls[j++] = temp;
    }
    
    //bottom row
    for (int i = 25; i < 800; i += 50)
    {
       Wall* temp = new Wall(i, 575.f);
       walls[j++] = temp;
    }

    //left column
    for (int i = 25; i < 600; i += 50)
    {
        Wall* temp = new Wall(25.f, i);
        walls[j++] = temp;
    }

    //right column
    for (int i = 25; i < 600; i += 50)
    {
        Wall* temp = new Wall(775.f, i);
        walls[j++] = temp;
    }

    isColliding = false;
}

Game::~Game()
{
    for(int i = 0; i < 56; i++)
    {
        delete walls[i];
    }
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

	player.boundingBox = player.sprite.getGlobalBounds();
    for (int i = 0; i < 56; i++)
    {
        if (player.boundingBox.intersects(walls[i]->collisionBox))
        {
            switch (player.dir)
            {
            case Player::Facing::UP:
                player.sprite.move(sf::Vector2f(0, 0.5f));
                break;

            case Player::Facing::DOWN:
                player.sprite.move(sf::Vector2f(0, -0.5f));
                break;

            case Player::Facing::LEFT:
                player.sprite.move(sf::Vector2f(0.5f, 0));
                break;

            case Player::Facing::RIGHT:
                player.sprite.move(sf::Vector2f(-0.5f, 0));
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
	
    for (int i = 0; i < 56; i++)
    {
        window->draw(walls[i]->sprite);
    }



    window->draw(player.sprite);

    

    window->display();
}