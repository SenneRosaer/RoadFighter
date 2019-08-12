//
// Created by sennerosaer on 7/23/19.
//

#include <cmath>
#include "MovingCar.h"


void roadfighter::MovingCar::update() {

}

void roadfighter::MovingCar::update(int speed, std::shared_ptr<roadfighter::Entity> Player) {
    int relativespeed = this->speed - speed;
    //use the relative speed of the player to simulate movement
    if (relativespeed < 0) {
        centralpos.second = centralpos.second - 0.01 * abs(relativespeed) / 10;
    } else {
        centralpos.second = centralpos.second + 0.01 * abs(relativespeed) / 10;
    }

    //If a player exists move to its position for a certain extent
    if(Player != nullptr) {
        std::shared_ptr<ObjBox> PlayerObjBox = Player->getObjbox();

        auto PlayerCentralPos = PlayerObjBox->centralpos;
        double x = abs(centralpos.first - PlayerCentralPos.first);
        double y = abs(centralpos.second - PlayerCentralPos.second);
        double distance = sqrt((x * x) + (y * y));
        if (distance <= 0.9 and y <= 0.2) {
            //Player to the right of the moving car
            if (centralpos.first < PlayerCentralPos.first) {
                if (movesLeft > 0) {
                    if (centralpos.first < -0.07) {
                        centralpos.first = centralpos.first + 0.03;
                        movesLeft = movesLeft - 0.03;

                    }
                }
            }
            //Player to the left of the moving car
            if (centralpos.first > PlayerCentralPos.first) {
                if (movesLeft > 0) {
                    if (centralpos.first > -1.84) {
                        centralpos.first = centralpos.first - 0.03;
                        movesLeft = movesLeft - 0.03;

                    }
                }
            }
        }
    }







    //Delete if out of bounds
    if (centralpos.second < -3.2) {
        toDel = true;
    } else if (centralpos.second > 3.5) {
        toDel = true;
    }
}

int roadfighter::MovingCar::getSpeed() {
    return speed;
}

int roadfighter::MovingCar::Delete() {
    return toDel;
}

std::shared_ptr<ObjBox> roadfighter::MovingCar::getObjbox() {
    return std::make_shared<ObjBox>(centralpos, height, width);
}

void roadfighter::MovingCar::setDelete(int del) {
    toDel = del;
}

bool roadfighter::MovingCar::Shoot() {
    return false;
}

roadfighter::MovingCar::MovingCar(std::shared_ptr<ConfigData> config) {
    roadfighter::Entity::Config = config;
    speed = config->getMaxSpeedPassingCar();
}
