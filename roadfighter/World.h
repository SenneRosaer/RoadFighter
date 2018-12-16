//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <memory>
#include "Entity.h"

namespace roadfighter {
    class World : public roadfighter::Entity {

        private:
            std::shared_ptr<roadfighter::Entity> Player;

        public:
            World();

            void draw() override;

            void setPlayer(const std::shared_ptr<Entity> &Player);

        void update() override;
    };

}

#endif //ROADFIGHTER_WORLD_H
