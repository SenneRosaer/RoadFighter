//
// Created by senne on 1/17/19.
//

#include "Observer.h"

Observer::Observer(std::shared_ptr<roadfighter::World> obj)
{
        this->obj = obj;
        auto wptr = std::shared_ptr<Observer>(this, [](Observer*) {});
        obj->attach(shared_from_this());
}

const std::shared_ptr<roadfighter::World>& Observer::getObj() const { return obj; }
