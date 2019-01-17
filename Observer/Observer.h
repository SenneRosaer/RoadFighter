//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_OBSERVER_H
#define ROADFIGHTER_OBSERVER_H

#include <memory>
#include "../roadfighter/Entity.h"
#include "../roadfighter/World.h"


class Observer {
    std::shared_ptr<roadfighter::World> obj;


public:
    Observer(std::shared_ptr<roadfighter::World> obj);

    virtual void update() = 0;

protected:

    const std::shared_ptr<roadfighter::World> &getObj() const;

    int score = 0;
};


#endif //ROADFIGHTER_OBSERVER_H
