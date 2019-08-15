//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_OBSERVER_H
#define ROADFIGHTER_OBSERVER_H

#include "../Game.h"
#include "../roadfighter/Entity.h"
#include "../roadfighter/World.h"
#include <memory>

/**
 * Base class for the observers
 */
class Observer : public std::enable_shared_from_this<Observer>
{

public:
        /**
         * Default constructor
         */
        Observer();

        /**
         * Update with an int parameter
         * @param score
         */
        virtual void update(int score) = 0;

        /**
         * Return the type of the observer
         * @return
         */
        virtual std::string getType() = 0;
};

#endif // ROADFIGHTER_OBSERVER_H
