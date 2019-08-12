//
// Created by senne on 12/21/18.
//

#include "PassingCar.h"

void roadfighter::PassingCar::update() {}

void roadfighter::PassingCar::update(int speed, std::shared_ptr<roadfighter::Entity> Player)
{
        int relativespeed = this->speed - speed;
        //Use the relative speed of the player to simulate movement
        if (relativespeed < 0) {
                centralpos.second = centralpos.second - 0.01 * abs(relativespeed) / 10;
        } else {
                centralpos.second = centralpos.second + 0.01 * abs(relativespeed) / 10;
        }

        //Delete if out of bounds
        if (centralpos.second < -3.2) {
                toDel = true;
        } else if (centralpos.second > 3.5) {
                toDel = true;
        }
}

int roadfighter::PassingCar::getSpeed() { return speed; }

int roadfighter::PassingCar::Delete() { return toDel; }

std::shared_ptr<ObjBox> roadfighter::PassingCar::getObjbox()
{
        return std::make_shared<ObjBox>(centralpos, height, width);
}

void roadfighter::PassingCar::setDelete(int del) { toDel = del; }

bool roadfighter::PassingCar::Shoot() { return false; }

roadfighter::PassingCar::PassingCar(std::shared_ptr<ConfigData> config) {
    roadfighter::Entity::Config = config;
    speed = config->getMaxSpeedPassingCar();
}
