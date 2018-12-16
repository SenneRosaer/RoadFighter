//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

namespace roadfighter {
    class Entity {

        public:
            virtual void draw() = 0;

            virtual void update() = 0;

            virtual void update(int speed) = 0;

            virtual int getSpeed() = 0;
    };

}

#endif //ROADFIGHTER_ENTITY_H
