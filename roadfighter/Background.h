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
            std::pair<double,double> centralpos1 = {-1, 0};
            std::pair<double,double> centralpos2 = {-1,6};
            std::pair<double,double> centralpos3 = {-1,12};

        bool toDel = false;

        public:
        void update() override;

        void update(int speed) override;

        int getSpeed() override;

        bool Delete() override;

        ObjBox getObjBox() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        void setDelete(bool del) override;

        bool Shoot() override;

    };
}

#endif //ROADFIGHTER_BACKGROUND_H
