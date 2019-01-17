//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_BULLETOBSERVER_H
#define ROADFIGHTER_BULLETOBSERVER_H


#include "Observer.h"

class BulletObserver : public Observer {
public:
    BulletObserver(std::shared_ptr<roadfighter::World> obj) : Observer(obj){}

    void update() override;

};


#endif //ROADFIGHTER_BULLETOBSERVER_H
