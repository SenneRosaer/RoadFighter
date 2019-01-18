//
// Created by senne on 1/16/19.
//

#ifndef ROADFIGHTER_BULLET_H
#define ROADFIGHTER_BULLET_H

#include "Entity.h"

namespace roadfighter {
class Bullet : public roadfighter::Entity
{
protected:
        int speed = 350;
        std::pair<double, double> pos;
        bool toDel = false;

public:
        /**
         * Updates the object with a speed
         * @param speed
         */
        void update(int speed) override;

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

        /**
         * Return if an object must shoot;
         * @return
         */
        bool Shoot() override;
};
} // namespace roadfighter

#endif // ROADFIGHTER_BULLET_H
