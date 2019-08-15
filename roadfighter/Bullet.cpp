//
// Created by senne on 1/16/19.
//

#include "Bullet.h"

void roadfighter::Bullet::update(int speed, std::shared_ptr<roadfighter::Entity> Player)
{
        // uses speed relative to the player to simulate the movement
        int relativespeed = this->speed - speed;
        if (relativespeed < 0) {
                pos.second = pos.second - 0.01 * abs(relativespeed) / 10;
        } else {
                pos.second = pos.second + 0.01 * abs(relativespeed) / 10;
        }

        if (pos.second < -3.2) {
                toDel = true;
        } else if (pos.second > 3.5) {
                toDel = true;
        }
}

void roadfighter::Bullet::update() {}

int roadfighter::Bullet::getSpeed() { return speed; }

int roadfighter::Bullet::Delete() { return toDel; }

void roadfighter::Bullet::setDelete(int del) { toDel = del; }

std::shared_ptr<ObjBox> roadfighter::Bullet::getObjbox() { return std::make_shared<ObjBox>(pos, 0, 0); }

bool roadfighter::Bullet::Shoot() { return false; }

roadfighter::Bullet::Bullet(std::shared_ptr<ConfigData> config)
{
        roadfighter::Entity::Config = config;
        speed = config->getBulletSpeed();
}
