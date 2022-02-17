#include "game.h"

#include <iostream>

Game::Game():
    event(), 
    player()
{
    //Creates Window
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "RogueLite", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);

    //Plays Music
    if (!music.openFromFile("assets/Tribal_Ritual.wav"))
    {
        std::cout << "Music improperly loaded..." << std::endl;
    }
    music.play();
    music.setLoop(true);

    //Top Wall Row
    int j = 0;
    for (int i = 25; i < 800; i += 50)
    {
        Wall* temp = new Wall((float)i, 25.f);
        walls[j++] = temp;
    }
    
    //Bottom Wall Row
    for (int i = 25; i < 800; i += 50)
    {
       Wall* temp = new Wall((float)i, 575.f);
       walls[j++] = temp;
    }

    //Left Wall Column
    for (int i = 25; i < 600; i += 50)
    {
        Wall* temp = new Wall(25.f, (float)i);
        walls[j++] = temp;
    }

    //Right Wall Column
    for (int i = 25; i < 600; i += 50)
    {
        Wall* temp = new Wall(775.f, (float)i);
        walls[j++] = temp;
    } 
}

Game::~Game()
{
    //Deletes All Perimeter Walls If Closed
    for(int i = 0; i < 56; i++)
    {
        delete walls[i];
    }
    delete window;
}

bool Game::isRunning() const
{
	return window->isOpen();
}

void Game::update()
{
    //Polls Windows Events
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

    //Checks If Player Collides With Walls
	player.collisionBox = player.sprite.getGlobalBounds();
    for (int i = 0; i < 56; i++)
    {
        if (player.collisionBox.intersects(walls[i]->collisionBox))
        {
            switch (player.dir)
            {
            case Player::Facing::UP:
                player.sprite.move(sf::Vector2f(0.f, 0.5f));
                break;

            case Player::Facing::LEFT:
                player.sprite.move(sf::Vector2f(0.5f, 0.f));
                break;

            case Player::Facing::RIGHT:
                player.sprite.move(sf::Vector2f(-0.5f, 0.f));
                break;
           
            case Player::Facing::DOWN:
                player.sprite.move(sf::Vector2f(0.f, -0.5f));
                break;
            }
            player.alterCollision(true);
        }
        
    }

    //Also Checks If Player Is Attacking
    player.attack();

    //Moves Player If Not Colliding
    if (!player.checkIfColliding())
    {
        player.move();
    }
    player.alterCollision(false);
}

void Game::render()
{
    //Clears Window
    window->clear(sf::Color(0, 0, 0));

    //Drawing Entities
	
    for (int i = 0; i < 56; i++)
    {
        window->draw(walls[i]->sprite);
    }

    window->draw(player.sprite);
    if (player.checkIfAttacking())
    {
        window->draw(player.weapon->sprite);
    }
    
    //Stop Drawing Entities

    //Draws To Window
    window->display();
}