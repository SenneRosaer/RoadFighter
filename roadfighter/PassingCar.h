//
// Created by senne on 12/21/18.
//

#ifndef ROADFIGHTER_PASSINGCAR_H
#define ROADFIGHTER_PASSINGCAR_H

#include "Entity.h"
#include <iostream>

namespace roadfighter {
class PassingCar : public roadfighter::Entity
{
protected:
        std::pair<double, double> centralpos;

        int speed;

        int toDel = 0;

        double height;

        double width;

public:

    PassingCar(std::shared_ptr<ConfigData> config);

    /**
     * Update
     */
        void update() override;

        /**
         * Update with a speed
         * @param speed
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Return the speed of the object
         * @return
         */
        int getSpeed() override;

        /**
         * Return if an object must be deleted
         * @return
         */
        int Delete() override;

        /**
         * Return a shared_ptr of the object box
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Set if an object must be deleted or not
         * @param del
         */
        void setDelete(int del) override;

        /**
         * Return if the object shot
         * @return
         */
        bool Shoot() override;
};
} // namespace roadfighter

#endif // ROADFIGHTER_PASSINGCAR_H
