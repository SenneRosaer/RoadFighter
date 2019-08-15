//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_BACKGROUND_H
#define ROADFIGHTER_BACKGROUND_H

#include "Entity.h"
#include <iostream>

namespace roadfighter {
    /**
     * Class that moves the background and makes sure it appears infinite
     */
    class Background : public Entity {
    protected:
        /**
         * X and Y positions of the first background sprite
         */
        std::pair<double, double> centralpos1 = {-1, -3};

        /**
         * X and Y positions of the second background sprite
         */
        std::pair<double, double> centralpos2 = {-1, 3};

        /**
         * X and Y positions of the third background sprite
         */
        std::pair<double, double> centralpos3 = {-1, 9};

        /**
         * X and Y positions of the finish background sprite
         */
        std::pair<double, double> centralposfin = {-1, 3};

        /**
         * Boolean that is true if we need to move the finish
         */
        bool moveFinish = false;

        /**
         * Object deletion status ( 0 = nothing, 1 = delete, 2 = respawn )
         */
        int toDel = 0;

        /**
         * Distance the car has travelled (to know when to show finish)
         */
        int CarTravelledDistance = 0;


    public:
        /**
         * Constructor with configuration data
         * @param config
         */
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
