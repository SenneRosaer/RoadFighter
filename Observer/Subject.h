//
// Created by senne on 1/18/19.
//

#ifndef ROADFIGHTER_SUBJECT_H
#define ROADFIGHTER_SUBJECT_H

#include <memory>

class Observer;

/**
 * Base class for subjects for observer pattern
 */
class Subject
{

public:
        /**
         * Attach an observer to the subject
         * @param observer
         */
        virtual void attach(std::shared_ptr<Observer> observer) = 0;

        /**
         * Notify the observers on a certain change
         */
        virtual void notify() = 0;
};

#endif // ROADFIGHTER_SUBJECT_H
