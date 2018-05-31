#ifndef Player_hpp
#define Player_hpp

#include "SDL2/SDL.h"

class Player
{
public:
    void draw(SDL_Renderer *renderer);
    void update(SDL_Event event);
    Player(int x, int y, int radius);
    ~Player();
    int x;
    int y;
    int radius;
    int speed = 10;
};

#endif /* Player_hpp */
