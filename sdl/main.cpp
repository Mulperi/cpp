// Coded with Let's Make Games -tutorial on Youtube
// By Mulperi

#include "Game.hpp"

Game *game = nullptr;

int main(int argc, const char *argv[])
{
    
    game = new Game();
    
    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }
    
    game->clean();
    
    return 0;
}
