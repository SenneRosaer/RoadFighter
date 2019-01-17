//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_ENTITY_H
#define ROADFIGHTER_ENTITY_H

#include <memory>
#include "../Utils/Utils.h"

namespace roadfighter {
    class Entity : public std::enable_shared_from_this<roadfighter::Entity> {

        public:
            virtual void draw() = 0;

            virtual void update() = 0;

            virtual void update(int speed) = 0;

            virtual int getSpeed() = 0;

            virtual bool Delete() = 0;

            virtual void setDelete(bool del) = 0;

            virtual ObjBox getObjBox() = 0;

            virtual bool Shoot() = 0;

            virtual std::shared_ptr<ObjBox> getObjbox() = 0;
    };

}

#endif //ROADFIGHTER_ENTITY_H
