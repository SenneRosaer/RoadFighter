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

            std::shared_ptr<roadfighter::Entity> Background;

        public:
            World();

            void draw() override;

            void setPlayer(const std::shared_ptr<Entity> &Player);

        void setBackground(const std::shared_ptr<Entity> &Background);

        void update() override;
    };

}

#endif //ROADFIGHTER_WORLD_H
