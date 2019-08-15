//
// Created by sennerosaer on 7/23/19.
//

#ifndef ROADFIGHTER_MOVINGCAR_H
#define ROADFIGHTER_MOVINGCAR_H

#include "Entity.h"
#include "iostream"

namespace roadfighter {
/**
 * The Moving car that moves to the player when it passes the player
 */
class MovingCar : public roadfighter::Entity
{
protected:
        /**
         * Pair of the doubles that contains the x and y position of the center of the object
         */
        std::pair<double, double> centralpos;

        /**
         * Speed of the object
         */
        int speed;

        /**
         * Object deletion status ( 0 = nothing, 1 = delete, 2 = respawn )
         */
        int toDel = 0;

        /**
         * Height of the object
         */
        double height;

        /**
         * Width of the object
         */
        double width;

        /**
         * Distance the car is allowed to move left or right
         */
        double movesLeft = 0.6;

public:
        /**
         * Constructor with the configuration data
         * @param config
         */
        MovingCar(std::shared_ptr<ConfigData> config);

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

#endif // ROADFIGHTER_MOVINGCAR_H
