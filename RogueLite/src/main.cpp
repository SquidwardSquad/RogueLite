#include <iostream>
#include <string>
#include <thread>

#include "game.h"

void timer(double* time, sf::Window* window);

int main()
{
    Game game;
    double gameTime;

    std::thread timerThread(timer, &gameTime, game.window);
    
    //Game Loop
    while (game.isRunning())
    {
        //Loop Init
        

        //Loop Update
        game.update();

        //Loop Render
        game.render();
    }

    timerThread.join();

    std::cout << "You lived for " << game.waveCount << " waves, and " << gameTime << " seconds before dying!\n" << std::endl;

    std::cout << "Press ENTER to close this window...";
    std::cin.get();

    return 0;
}

void timer(double* time, sf::Window* window)
{
    sf::Clock clock;
    sf::Time gameTime;

    while (window->isOpen()){}
    gameTime = clock.getElapsedTime();
    *time = gameTime.asSeconds();
}
