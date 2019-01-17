//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_WORLD_H
#define ROADFIGHTER_WORLD_H

#include <memory>
#include "Entity.h"
#include <vector>

class Observer;

namespace roadfighter {
    class World : public roadfighter::Entity {

        private:
            std::shared_ptr<roadfighter::Entity> Player;

            std::shared_ptr<roadfighter::Entity> Background;

            std::vector<std::shared_ptr<roadfighter::Entity>> passingCars;

            std::vector<std::shared_ptr<roadfighter::Entity>> Bullets;

            bool shoot = false;

            std::vector<std::shared_ptr<Observer>> observers;

    public:

        int respawnTimer = 30;

        public:
            World();

            void draw() override;

            void setPlayer(const std::shared_ptr<Entity> &Player);

        void setBackground(const std::shared_ptr<Entity> &Background);

        void update() override;

        void update(int speed) override;

        int getSpeed() override;

        const std::shared_ptr<Entity> &getPlayer() const;

        const std::vector<std::shared_ptr<Entity>> &getPassingCars() const;

        void addPassingCar(std::shared_ptr<roadfighter::Entity> car);

        void addBullet(std::shared_ptr<roadfighter::Entity> bullet);

        bool Delete() override;

        void Collision();

        ObjBox getObjBox() override;

        std::shared_ptr<ObjBox> getObjbox() override;

        void setDelete(bool del) override;

        bool Shoot() override;

        bool isShoot() const;

        void notify();
    };

}

#endif //ROADFIGHTER_WORLD_H
