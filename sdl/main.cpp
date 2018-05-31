#include "Game.hpp"

Game *game = nullptr; // Not sure what the hell is happening here

int main(int argc, const char *argv[])
{
    game = new Game();
    while (game->running)
    {
        game->update();
        game->render();
    }
    game->clean();
    
    return 0;
}
