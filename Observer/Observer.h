//
// Created by senne on 1/17/19.
//

#ifndef ROADFIGHTER_OBSERVER_H
#define ROADFIGHTER_OBSERVER_H

#include "../Game.h"
#include "../roadfighter/Entity.h"
#include "../roadfighter/World.h"
#include <memory>

class Observer : public std::enable_shared_from_this<Observer>
{
        std::shared_ptr<roadfighter::World> obj;

public:
        Observer(std::shared_ptr<roadfighter::World> obj);

        virtual void update(int score) = 0;

protected:
        const std::shared_ptr<roadfighter::World>& getObj() const;
};

#endif // ROADFIGHTER_OBSERVER_H
