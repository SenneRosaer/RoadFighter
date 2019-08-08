//
// Created by senne on 12/15/18.
//

#include "Random.h"
#include <stdlib.h>
#include <time.h>

double Random::getRandom() {
    srand(time(NULL));
    int random = rand() % positions.size() + 0;
    return positions[random];
}

double Random::getRandom2() {
    srand(time(NULL));
    int random = rand() % 2 + 0;
    return random;
}

double Random::getRandom3() {
    srand(time(NULL));
    int random = rand() % positionsRock.size() + 0;
    return positionsRock[random];
}


int Random::getRandom4(){
    srand(time(NULL));
    int random = rand() % positionsRock.size() + 0;
    return random;
}