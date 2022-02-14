#include <iostream>

#include "game.h"

int main()
{
    Game game;
    
    //Game Loop
    while (game.isRunning())
    {
        //Loop Init
        

        //Loop Update
        game.update();

        //Loop Render
        game.render();
    }

    return 0;
}