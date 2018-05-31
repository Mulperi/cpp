#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h" // just SDL.h in Windows

class Game
{
    
public:
    Game();  // Constructor
    ~Game(); // Deconstructor
    
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void render();
    void clean();
    bool running;
    
private:
    int count;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif /* Game_hpp */
