//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITYFACTORY_H
#define ROADFIGHTER_ENTITYFACTORY_H

#include "Entity.h"
#include <memory>

namespace roadfighter {
class EntityFactory
{

public:
        /**
         * Create a playercar
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar() = 0;

        /**
         * Create a background
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createBackground() = 0;

        /**
         * Create a passing car
         * @param i = random position
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createPassingCar(double i) = 0;

        /**
         * Create a bullet
         * @param first = x position of car
         * @param second = y position of car
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createBullet(double first, double second) = 0;
};
} // namespace roadfighter

#endif // ROADFIGHTER_ENTITYFACTORY_H
