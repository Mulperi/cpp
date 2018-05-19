#include "player.hpp"

// Player method definitions

int Player::getHealth()
{
    return this->hp;
}

Player::Player(int hp) // Parametrized constructor
{
    this->hp = hp;
}

Player::Player() // Default constructor
{
    this->hp = 200;
}