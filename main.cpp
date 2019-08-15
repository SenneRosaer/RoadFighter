#include "Game.h"
#include "Exception_class/GameError.h"
#include <iostream>

//TODO CLANG TIDY
int main() {
    try {
        Game TestGame;
        TestGame.run();
    } catch (GameError& e){
        std::cerr<< "Error cannot be handled" << std::endl;
        return 0;
    }
}