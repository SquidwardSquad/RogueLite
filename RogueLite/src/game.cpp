#include "game.h"

#include <iostream>

Game::Game():
    event(), 
    player()
{
    //Creates Window
	videoMode.width = 800;
	videoMode.height = 600;
	window = new sf::RenderWindow(videoMode, "RoboSlayer", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);

    //Plays Music
    if (!music.openFromFile("assets/Tribal_Ritual.wav"))
    {
        std::cout << "Music improperly loaded..." << std::endl;
    }
    music.play();
    music.setLoop(true);
    music.setVolume(10.f);

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

    j = 0;
    //Initial Enemy Creation
    for (int i = 100; i < 600; i += 100)
    {
        Enemy* temp = new Enemy(100, i);
        enemies[j] = temp;
        j++;
    }

    diffScale = 1;
    waveCount = 1;

    //Refreshes Console On StartUp
    for (int i = 0; i < 100; i++)
    {
        std::cout << std::endl;
    }

    std::cout << "Starting Wave " << waveCount  << "!" << std::endl;
}

Game::~Game()
{
    //Deletes All Remaining Enemies
    for (int i = 0; i < 5; i++)
    {
        if (enemies[i]->isAlive)
        { 
            delete enemies[i];
        }
    }

    //Deletes All Perimeter Walls If Closed
    for (int i = 0; i < 56; i++)
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

    //Checks If Enemies Are Alive, And Spawns New Ones
    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        if (!enemies[i]->isAlive)
        {
            j++;
        }
        if (j == 5)
        {
            for (int i = 0; i < 5; i++)
            {
                delete enemies[i];
                enemies[i] = nullptr;
            }
            j = 0;
            for (int i = 100; i < 600; i += 100)
            {
                Enemy* temp = new Enemy(100, i, diffScale);
                enemies[j] = temp;
                j++;
            }
            diffScale += 0.5;
            std::cout << "Wave " << waveCount << " complete!\n" << std::endl;
            waveCount++;
            std::cout << "Starting Wave " << waveCount << "!" << std::endl;
        }
    }

    //Checks If Player Collides With Walls
    if (player.isAlive)
    {
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
    }

    //Checks If Enemies Attacked Player (Ends Game)
    for (int i = 0; i < 5; i++)
    {
        if (enemies[i]->isAlive && player.isAlive)
        {
            enemies[i]->collisionBox = enemies[i]->sprite.getGlobalBounds();
            player.collisionBox = player.sprite.getGlobalBounds();
            if (enemies[i]->collisionBox.intersects(player.collisionBox))
            {
                player.isAlive = false;
                window->close();
                std::cout << "GAME OVER!!!\n" << std::endl;
                
            }
        }
    }

    //Checks If Enemies Get Hit
    if (player.isAttacking)
    { 
        for (int i = 0; i < 5; i++)
        {
            if (enemies[i]->isAlive)
            {
                enemies[i]->collisionBox = enemies[i]->sprite.getGlobalBounds();
                for (int j = 0; j < 56; j++)
                {
                    if (enemies[i]->collisionBox.intersects(player.weapon->collisionBox))
                    {
                        enemies[i]->isAlive = false;
                    }
                }
            }
        }
    }

    //Move Enemies Back and Forth
    for (int i = 0; i < 5; i++)
    {
        if (enemies[i]->isAlive)
        {
            if (enemies[i]->getPos().x > 700)
            {
                enemies[i]->speed = (float)(-4.f * diffScale);
            }
            if (enemies[i]->getPos().x < 100)
            {
                enemies[i]->speed = (float)(4.f * diffScale);
            }
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


    //Moves Enemy
    for (int i = 0; i < 5; i++)
    {
        enemies[i]->move();
    }
}

void Game::render()
{

    //Clears Window
    window->clear(sf::Color(43, 29, 20));

    //Drawing Entities
	
    for (int i = 0; i < 56; i++)
    {
        window->draw(walls[i]->sprite);
    }

    if (player.isAlive)
        { 
        window->draw(player.sprite);
        if (player.checkIfAttacking())
        {
            window->draw(player.weapon->sprite);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (enemies[i]->isAlive)
        { 
            window->draw(enemies[i]->sprite);
        }
    }
    
    //Stop Drawing Entities
    
    //Displays Window
    window->display();
}