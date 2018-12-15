//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITYFACTORY_H
#define ROADFIGHTER_ENTITYFACTORY_H

#include <memory>
#include "Entity.h"

namespace roadfighter {
    class EntityFactory {

    public:

        virtual std::shared_ptr<roadfighter::Entity> createPlayerCar() = 0;

    };
}

#endif //ROADFIGHTER_ENTITYFACTORY_H
