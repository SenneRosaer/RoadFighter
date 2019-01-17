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

            std::pair<double,double> centralpos = {-0.9, -2};

            int speed = 0;

            bool shoot = false;

            int reload = 30;

            bool reloading = false;

            void UpdateMovement(std::vector<std::string> inputs);

            void move(std::string input);

            bool toDel = false;

        double height;

        double width;

    public:
        void update(int speed) override;

        int getSpeed() override;

        bool Delete() override;

        ObjBox getObjBox() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        void setDelete(bool del) override;

        bool Shoot() override;

    public:
    };
}

#endif //ROADFIGHTER_PLAYERCAR_H
