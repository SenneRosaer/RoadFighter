#include "Exception_class/GameError.h"
#include "Game.h"
#include <iostream>

int main()
{
        try {
                Game TestGame;
                TestGame.run();
        } catch (GameError& e) {
                std::cerr << "Error cannot be handled" << std::endl;
                return 0;
        }
}