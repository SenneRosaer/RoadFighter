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

    /**
     * Constructor with configuration data
     * @param config
     */
    PassingCar(std::shared_ptr<ConfigData> config);

    /**
     * Update
     */
        void update() override;

    /**
         * Updates the object with extra parameters
         * @param speed
         * @param Player
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

    /**
     * Returns the speed of the object
     * @return speed
     */
        int getSpeed() override;

    /**
     * Returns a certain value to determine the delete status
     * 0 = nothing, 1 = delete, 2 = respawn
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
