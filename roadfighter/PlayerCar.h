//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_PLAYERCAR_H
#define ROADFIGHTER_PLAYERCAR_H

#include "Entity.h"
#include <iostream>


namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
        protected:
            std::pair<float,float> centralpos = {0, -2};
    };
}

#endif //ROADFIGHTER_PLAYERCAR_H
