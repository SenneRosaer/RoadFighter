//
// Created by sennerosaer on 7/23/19.
//

#ifndef ROADFIGHTER_MOVINGCAR_H
#define ROADFIGHTER_MOVINGCAR_H

#include "iostream"
#include "Entity.h"

namespace roadfighter {
    class MovingCar : public roadfighter::Entity {
    protected:
        std::pair<double, double> centralpos;

        int speed;

        int toDel = 0;

        double height;

        double width;

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
}

#endif //ROADFIGHTER_MOVINGCAR_H
