//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_PLAYERCAR_H
#define ROADFIGHTER_PLAYERCAR_H

#include "Entity.h"
#include <iostream>
#include <vector>

namespace roadfighter {
class PlayerCar : public roadfighter::Entity
{
protected:
        std::pair<double, double> centralpos = {-0.9, -2};

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
        /**
         * Update object with a speed
         * @param speed
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Return the speed of the object
         * @return
         */
        int getSpeed() override;

        /**
         * Return if the object has to be deletes
         * @return
         */
        bool Delete() override;

        /**
         * Returns a shared_ptr of the object box
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Set if the object must be deleted
         * @param del
         */
        void setDelete(bool del) override;

        /**
         * Return if the object shot
         * @return
         */
        bool Shoot() override;

public:
};
} // namespace roadfighter

#endif // ROADFIGHTER_PLAYERCAR_H
