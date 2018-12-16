//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_PLAYERCAR_H
#define ROADFIGHTER_PLAYERCAR_H

#include "Entity.h"
#include <iostream>
#include <vector>

namespace roadfighter {
    class PlayerCar : public roadfighter::Entity {
        protected:

            std::pair<float,float> centralpos = {0, -2};

            int speed = 0;

            void UpdateMovement(std::vector<std::string> inputs);

            void move(std::string input);

    public:
        void update(int speed) override;

        int getSpeed() override;

    public:
    };
}

#endif //ROADFIGHTER_PLAYERCAR_H
