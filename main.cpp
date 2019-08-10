#include "Game.h"
#include "Exception_class/GameError.h"
#include <iostream>

// TODO rename classes (not bulletSFMl just bullet)
// TODO ?? alle return waardes in 1 struct zoda het in 1 functie kan ??
// TODO betere mnaier voor passing cars te spawnen zodat met distance het moeilijker is
// TODO meer lanes waarin de auto's kunnen spawnen
// TODO bewegingen korter maken zodat schieten beter gaat .
// TODO beter manier voor delay respawn
// TODO fix schieten met auto er onder is rip
int main() {
    try {
        Game TestGame;
        TestGame.run();
    } catch (GameError& e){
        std::cerr<< "Error cannot be handled" << std::endl;
        return 0;
    }
}