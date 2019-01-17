//
// Created by senne on 12/21/18.
//

#ifndef ROADFIGHTER_PASSINGCAR_H
#define ROADFIGHTER_PASSINGCAR_H

#include "Entity.h"
#include <iostream>

namespace roadfighter {
    class PassingCar : public roadfighter::Entity {
        protected:
                std::pair<double,double> centralpos;

                int speed = 150;

        bool toDel = false;

        double height;

        double width;

    public:

        //Auto's gaan bij genereren
        void update() override;

        //Beweging van de bestaande auto's
        void update(int speed) override;

        int getSpeed() override;

        bool Delete() override;

        ObjBox getObjBox() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        void setDelete(bool del) override;

        bool Shoot() override;
    };
}

#endif //ROADFIGHTER_PASSINGCAR_H
