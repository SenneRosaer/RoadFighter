//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_DISTANCEOBSERVER_H
#define ROADFIGHTER_DISTANCEOBSERVER_H


#include "Observer.h"

class DistanceObserver: public Observer {
public:
    DistanceObserver(std::shared_ptr<roadfighter::World> obj) : Observer(obj){}

    void update() override;
};


#endif //ROADFIGHTER_DISTANCEOBSERVER_H
