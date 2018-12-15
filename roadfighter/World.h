//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <memory>
#include "Entity.h"

namespace roadfighter {
    class World : public roadfighter::Entity {

        public:
            std::shared_ptr<roadfighter::Entity> Player;

    };

}

#endif //ROADFIGHTER_WORLD_H
