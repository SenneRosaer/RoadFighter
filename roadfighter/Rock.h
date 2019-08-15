//
// Created by sennerosaer on 7/22/19.
//

#ifndef ROADFIGHTER_ROCK_H
#define ROADFIGHTER_ROCK_H

#include "Entity.h"

namespace roadfighter {
    /**
     * The rock obstacle that doesn't have any speed so comes at the player faster
     */
    class Rock : public roadfighter::Entity {
    protected:
        /**
         * Pair of the doubles that contains the x and y position of the center of the object
         */
        std::pair<double, double> centralpos;

        /**
         * Speed of the object
         */
        int speed = 0;

        /**
         * Object deletion status ( 0 = nothing, 1 = delete, 2 = respawn )
         */
        int toDel = 0;

        /**
         * Height of object
         */
        double height;

        /**
         * Width of object
         */
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
