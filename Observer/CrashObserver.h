//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_CRASHOBSERVER_H
#define ROADFIGHTER_CRASHOBSERVER_H


#include "Observer.h"

class CrashObserver : public Observer {
public:
    CrashObserver(std::shared_ptr<roadfighter::World> obj) : Observer(obj){}

    void update() override;

};


#endif //ROADFIGHTER_CRASHOBSERVER_H
