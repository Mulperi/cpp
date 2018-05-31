#include "Game.hpp"
#include "Player.hpp"

Player p1(50, 50, 50);

Game::Game()
{
    this->init("Basic Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, false);
}

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 0.1);
    SDL_RenderClear(renderer); // Clear screen with the color above
    p1.draw(renderer);
    SDL_RenderPresent(renderer);
};

void Game::update()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    
    p1.update(event);
    
    switch (event.type)
    {
        case SDL_QUIT: // Click window close
            running = false;
            break;
    }
};

Game::~Game(){};
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flags = 0;
        if (fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        running = true;
    }
    else
    {
        running = false;
    }
};
