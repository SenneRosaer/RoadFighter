//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_BACKGROUND_H
#define ROADFIGHTER_BACKGROUND_H

#include "Entity.h"
#include <iostream>

namespace roadfighter {
    class Background: public Entity {
        protected:
            std::pair<float,float> centralpos1 = {-1, 0};
            std::pair<float,float> centralpos2 = {-1,6};
            std::pair<float,float> centralpos3 = {-1,12};

        public:
        void update() override;

        void update(int speed) override;

        int getSpeed() override;
    };
}

#endif //ROADFIGHTER_BACKGROUND_H
