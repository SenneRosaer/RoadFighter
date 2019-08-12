//
// Created by sennerosaer on 7/22/19.
//

#ifndef ROADFIGHTER_ROCK_H
#define ROADFIGHTER_ROCK_H

#include "Entity.h"

namespace roadfighter {
    class Rock : public roadfighter::Entity {
    protected:
        std::pair<double, double> centralpos;

        int speed = 0;

        int toDel = 0;

        double height;

        double width;

    public:
        /**
         * Updates the object with extra parameters
         * @param speed
         * @param Player
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Update the object
         */
        void update() override;

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
         * Set if an object must be deleted
         * @param del
         */
        void setDelete(int del) override;

        /**
         * Return the object box of an object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Return if we have to shoot but this function is only used by the player
         * @return
         */
        bool Shoot() override;


    };
}

#endif //ROADFIGHTER_ROCK_H
