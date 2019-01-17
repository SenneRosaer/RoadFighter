//
// Created by senne on 1/16/19.
//

#ifndef ROADFIGHTER_BULLET_H
#define ROADFIGHTER_BULLET_H

#include "Entity.h"

namespace roadfighter {
    class Bullet : public roadfighter::Entity {
    protected:
            int speed = 350;
            std::pair<double,double> pos;
            bool toDel = false;

        public:
        void update(int speed) override;

        void update() override;

        int getSpeed() override;

        bool Delete() override;

        void setDelete(bool del) override;

        ObjBox getObjBox() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        bool Shoot() override;

    };
}

#endif //ROADFIGHTER_BULLET_H
