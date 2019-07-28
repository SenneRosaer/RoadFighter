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

        bool toDel = false;

        double height;

        double width;

    public:
        /**
         * Updates the object with a speed
         * @param speed
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Update the object
         */
        void update() override;

        /**
         * Return the speed of the object
         * @return
         */
        int getSpeed() override;

        /**
         * Return if an object must be deleted
         * @return
         */
        bool Delete() override;

        /**
         * Set if an object must be deleted
         * @param del
         */
        void setDelete(bool del) override;

        /**
         * Return the object box of an object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;


        bool Shoot() override;


    };
}

#endif //ROADFIGHTER_ROCK_H
