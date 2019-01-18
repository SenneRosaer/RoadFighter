//
// Created by senne on 12/15/18.
//

#include "Random.h"
#include <stdlib.h>
#include <time.h>

double Random::getRandom()
{
        srand(time(NULL));
        int random = rand() % positions.size() + 0;
        return positions[random];
}
