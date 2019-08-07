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

        int speed = 150;

        int toDel = 0;

        double height;

        double width;

        double movesLeft = 0.6;



    public:
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
}

#endif //ROADFIGHTER_MOVINGCAR_H
