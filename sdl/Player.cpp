#include "Player.hpp"
#include "SDL2/SDL.h"

Player::Player(int x, int y, int radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

void Player::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, x - 10, y - 10, x + 10, y + 10);
    SDL_RenderDrawLine(renderer, x + 10, y + 10, x - 10, y - 10);
}

void Player::update(SDL_Event event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
        {
            case SDLK_LEFT:
                x -= speed;
                break;
            case SDLK_RIGHT:
                x += speed;
                break;
            case SDLK_UP:
                y -= speed;
                break;
            case SDLK_DOWN:
                y += speed;
                break;
        }
        default:
            break;
    }
}

Player::~Player(){};
