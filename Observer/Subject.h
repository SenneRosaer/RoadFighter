//
// Created by senne on 1/18/19.
//

#ifndef ROADFIGHTER_SUBJECT_H
#define ROADFIGHTER_SUBJECT_H

#include <memory>

class Observer;

class Subject
{

public:
        virtual void attach(std::shared_ptr<Observer> observer) = 0;

        virtual void notify(int scoreUpdate) = 0;
};

#endif // ROADFIGHTER_SUBJECT_H
