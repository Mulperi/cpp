#ifndef PLAYER_H // If not defined, run stuff below
#define PLAYER_H

// Declaration or prototype of class
class Player
{
  public:
    int hp;
    int getHealth();
    Player(int hp); // Parametrized constructor
    Player();       // Default constructor
};

#endif
