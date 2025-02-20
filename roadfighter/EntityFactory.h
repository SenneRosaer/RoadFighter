//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITYFACTORY_H
#define ROADFIGHTER_ENTITYFACTORY_H

#include "AIRacer.h"
#include "Boss.h"
#include "Entity.h"
#include <memory>

namespace roadfighter {
/**
 * Factory for creating entities
 */
class EntityFactory
{

public:
        /**
         * Create a playercar
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar(int level) = 0;

        /**
         * Create a background
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createBackground(int i) = 0;

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

        /**
         * create a rock
         * @param i = position
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createRock(double i) = 0;

        /**
         * create a moving car
         * @param i = random position
         * @return
         */
        virtual std::shared_ptr<roadfighter::Entity> createMovingCar(double i) = 0;

        /**
         * Create an ai racer
         * @return
         */
        virtual std::shared_ptr<roadfighter::AIRacer> createAI() = 0;

        /**
         * Create the boss
         * @return
         */
        virtual std::shared_ptr<roadfighter::Boss> createBoss() = 0;
};
} // namespace roadfighter
// namespace roadfighter

#endif // ROADFIGHTER_ENTITYFACTORY_H
