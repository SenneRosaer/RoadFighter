//
// Created by senne on 12/16/18.
//

#ifndef ROADFIGHTER_BACKGROUND_H
#define ROADFIGHTER_BACKGROUND_H

#include "Entity.h"
#include <iostream>

namespace roadfighter {
class Background : public Entity
{
protected:
        std::pair<double, double> centralpos1 = {-1, 0};
        std::pair<double, double> centralpos2 = {-1, 6};
        std::pair<double, double> centralpos3 = {-1, 12};

        bool toDel = false;

public:
        /**
         * Updated the object
         */
        void update() override;

        /**
         * Updates the object with a speed
         * @param speed
         */
        void update(int speed, std::shared_ptr<roadfighter::Entity> Player) override;

        /**
         * Returns the speed of the object
         * @return
         */
        int getSpeed() override;

        /**
         * Returns if the object must be deleted
         * @return
         */
        bool Delete() override;

        /**
         * Return the object box of the object
         * @return
         */
        std::shared_ptr<ObjBox> getObjbox() override;

        /**
         * Sets if the object must be deleted
         * @param del
         */
        void setDelete(bool del) override;

        /**
         * Return if the object shoots
         * @return
         */
        bool Shoot() override;
};
} // namespace roadfighter

#endif // ROADFIGHTER_BACKGROUND_H
