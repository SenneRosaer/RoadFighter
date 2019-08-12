//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_BACKGROUND_H
#define ROADFIGHTER_BACKGROUND_H

#include "Entity.h"
#include <iostream>

namespace roadfighter {
    class Background : public Entity {
    protected:
        std::pair<double, double> centralpos1 = {-1, -3};
        std::pair<double, double> centralpos2 = {-1, 3};
        std::pair<double, double> centralpos3 = {-1, 9};

        std::pair<double, double> centralposfin = {-1, 3};

        bool moveFinish = false;

        int toDel = 0;

        int CarTravelledDistance = 0;

        bool bossfight = false;

    public:
        Background(std::shared_ptr<ConfigData> config);

        /**
         * Updates the object
         */
        void update() override;

        /**
         * Updates the object with extra parameters
         * The speed is used to see how much we need to move the backgrounds
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
         * Return the object box of the object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Sets if the object must be deleted
         * @param del
         */
        void setDelete(int del) override;

        /**
         * Return if the object shoots
         * @return
         */
        bool Shoot() override;
    };
} // namespace roadfighter

#endif // ROADFIGHTER_BACKGROUND_H
