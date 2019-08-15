//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_PLAYERCAR_H
#define ROADFIGHTER_PLAYERCAR_H

#include "Entity.h"
#include <iostream>
#include <vector>

namespace roadfighter {
/**
 * The player that can be controlled
 */
class PlayerCar : public roadfighter::Entity
{
protected:
        /**
         * Pair of the doubles that contains the x and y position of the center of the object
         */
        std::pair<double, double> centralpos = {-0.9, -2};

        /**
         * Speed of object
         */
        int speed = 0;

        /**
         * maximum speed of object
         */
        int maxSpeed;

        /**
         * Boolean that is true if we need to shoot
         */
        bool shoot = false;

        /**
         * Reload timer
         */
        int reload;

        /**
         * Value that reload timer starts at
         */
        int reloadval;

        /**
         * Boolean that is true if we are reloading
         */
        bool reloading = false;

        /**
         * Updates the movements depending on the inputs
         * @param inputs
         */
        void UpdateMovement(std::vector<std::string> inputs);

        /**
         * Moves the object left or right depenting on inputs
         * @param input
         */
        void move(std::string input);

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
         * Distance that the car travelled
         */
        int CarTravelledDistance = 0;

        /**
         * Boolean that is true if the car is finished
         */
        bool finished = false;

        /**
         * Timer until respawn
         */
        int respawntimer;

        /**
         * Time that the respawn timer starts at
         */
        int respawntimerVal;

        /**
         * Boolean that is true if we cannot do any actions
         */
        bool disableActions = false;

        /**
         * Current level
         */
        int level;

        /**
         * Boolean that is true if we are in bossfight
         */
        bool bossfight = false;

        /**
         * Acceleration of the player
         */
        int acceleration;

public:
        /**
         * Constructor with configuration data
         * @param config
         */
        PlayerCar(std::shared_ptr<ConfigData> config);

        /**
         * Updates the object with extra parameters
         * this function is not used since we already have the needed parameters
         *
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
         * Return if the object has to be deletes
         * @return
         */
        int Delete() override;

        /**
         * Returns a shared_ptr of the object box
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Set if the object must be deleted
         * @param del
         */
        void setDelete(int del) override;

        /**
         * Return if the object shot
         * @return
         */
        bool Shoot() override;

        /**
         * Update function that controls bossfight, respawn and finish
         */
        void update() override;

public:
};
} // namespace roadfighter

#endif // ROADFIGHTER_PLAYERCAR_H
