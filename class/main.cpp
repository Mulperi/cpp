#include <iostream>
#include "player.hpp"

int main()
{
    Player p1(50);
    std::cout << p1.getHealth() << std::endl; // 50

    Player p2(100);
    std::cout << p2.getHealth() << std::endl; // 100

    Player p3;
    std::cout << p3.getHealth() << std::endl; // 200

    return 0;
}