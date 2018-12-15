//
// Created by senne on 12/15/18.
//

#include "Random.h"
#include <stdlib.h>
#include <time.h>

int Random::getRandom() {
    srand( time(NULL));
    int random = rand() % 4+ 0;

}
