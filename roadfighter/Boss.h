//
// Created by sennerosaer on 8/8/19.
//

#ifndef ROADFIGHTER_BOSS_H
#define ROADFIGHTER_BOSS_H

#include <iostream>
#include "Entity.h"
#include "vector"

namespace roadfighter {
    /**
     *  The boss that attacks the player on an certain interval and appears at the end of level 3
     */
    class Boss : public roadfighter::Entity {
    protected:
        /**
         * Height of the object
         */
        double height;

        /**
         * Width of the object
         */
        double width;

        /**
         * Pair of the doubles that contains the x and y position of the center of the object
         */
        std::pair<double, double> centralpos = {-0.9, 3.2};

        /**
         * Starting speed of the boss (so he moves from above the screen to in the screen)
         */
        int Startspeed = 90;

        /**
         * Final speed of the boss
         */
        int endSpeed = 100;

        /**
         * Current speed of the boss
         */
        int currentspeed;

        /**
         * Object deletion status ( 0 = nothing, 1 = delete, 2 = respawn )
         */
        int toDel = 0;

        /**
         * Boolean that is true if the game is finished
         */
        bool finished = false;

        /**
         * String for left and right movement
         */
        std::string move = "left";

        /**
         * Timer between attacks
         */
        int attackTimer;

        /**
         * Value the timer between attacks starts at
         */
        int attackTimerVal;

        /**
         * Positions of the spawned rocks
         */
        std::vector<double> rockPos;

        /**
         * Boolean that is true if rocks have been spawned and the game needs to create them
         */
        bool getRocks = false;

        /**
         * Lifes of the boss
         */
        int life = 5;


    public:
        /**
         * Constructor with the configuration data
         * @param config
         */
        Boss(std::shared_ptr<ConfigData> config);

        /**
         * Updates the object
         * makes the boss move left and right and chooses positions to spawn his attacks
         */
        void update() override;

        /**
         * Updates the object with extra parameters but is not used in this case since we don't parameters to upate
         * is specified because it is pure virtual
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
         * Set the delete variable to a certain value
         * @param del
         */
        void setDelete(int del) override;

        bool Shoot() override;

        /**
         * Return the object box of the object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Returns if rocks have to be created by a factory
         * @return
         */
        bool isGetRocks() const;

        /**
         * Sets the rock variable to true or false
         * @param getRocks
         */
        void setGetRocks(bool getRocks);

        /**
         * Returns the position of rocks to spawn
         * @return
         */
        const std::vector<double> &getRockPos() const;

        /**
         * Return the amount of lifes
         * @return
         */
        int getLife() const;

        /**
         * Set the amount of lifes
         * @param life
         */
        void setLife(int life);

    };
}


#endif //ROADFIGHTER_BOSS_H
