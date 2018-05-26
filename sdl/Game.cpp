#include "Game.hpp"

Game::Game()
{
    this->init("Basic Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, false);
}
Game::~Game(){};

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    // SDL INIT -> GAME RUNNING
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "subsystems initialized" << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "window created" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            std::cout << "renderer created" << std::endl;
        }
        
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
};

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type)
    {
        case SDL_QUIT: // Clicking window close
            isRunning = false;
            break;
        default:
            break;
    }
};

void Game::update()
{
    count++; // Just to test gameloop
    std::cout << count << std::endl;
    
};

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 50, 50, 100, 100);
    SDL_RenderPresent(renderer);
};

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
};
