//
// Created by sennerosaer on 8/8/19.
//

#ifndef ROADFIGHTER_BOSS_H
#define ROADFIGHTER_BOSS_H

#include <iostream>
#include "Entity.h"
#include "vector"

namespace roadfighter {
    class Boss : public roadfighter::Entity {
    protected:
        double height;

        double width;

        std::pair<double, double> centralpos = {-0.9, 3.2};

        int Startspeed = 90;

        int endSpeed = 100;

        int currentspeed;

        int toDel = 0;


        bool finished = false;

        std::string move = "left";

        int attackTimer;
        int attackTimerVal;

        std::vector<double> rockPos;

        bool getRocks = false;

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
