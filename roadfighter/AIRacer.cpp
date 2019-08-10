//
// Created by sennerosaer on 8/7/19.
//

#include "AIRacer.h"

void roadfighter::AIRacer::draw() {

}

void roadfighter::AIRacer::update(int speed, std::shared_ptr<roadfighter::Entity> Player) {

}

int roadfighter::AIRacer::getSpeed() {
    return speed;
}

int roadfighter::AIRacer::Delete() {
    return toDel;
}

void roadfighter::AIRacer::setDelete(int del) {
    toDel = del;
}

bool roadfighter::AIRacer::Shoot() {
    return false;
}

std::shared_ptr<ObjBox> roadfighter::AIRacer::getObjbox() {
    return std::make_shared<ObjBox>(centralpos, height, width);
}

void roadfighter::AIRacer::update() {
    CarTravelledDistance = CarTravelledDistance + speed;
    if(CarTravelledDistance > 100000){
        finished = true;
    }

    //2 is for respawning the car
    if(toDel ==  2){
        speed = 0;
        respawntimer--;
        disableActions = true;
        if(respawntimer <= 0){
            toDel = 0;
            respawntimer = 60;
            disableActions = false;
        }
    }

}

void roadfighter::AIRacer::updateMovement(std::vector<std::shared_ptr<roadfighter::Entity>> passingCars,std::vector<std::shared_ptr<roadfighter::Entity>> MovingCars,std::vector<std::shared_ptr<roadfighter::Entity>> Rocks,
                                          std::shared_ptr<roadfighter::Entity> player) {

    int relativespeed = this->speed - player->getSpeed();
    if (relativespeed < 0) {
        centralpos.second = centralpos.second - 0.01 * abs(relativespeed) / 10;
    } else {
        centralpos.second = centralpos.second + 0.01 * abs(relativespeed) / 10;
    }

    if(!disableActions) {
        if (speed < maxspeed) {
            speed = speed + 3;
        }



        std::shared_ptr<roadfighter::Entity> carToMoveFor = nullptr;
        std::string movement = "";

        std::vector<std::shared_ptr<roadfighter::Entity>> obj;
        obj.insert(obj.end(), passingCars.begin(), passingCars.end());
        obj.insert(obj.end(), MovingCars.begin(), MovingCars.end());
        obj.insert(obj.end(), Rocks.begin(), Rocks.end());
        obj.push_back(player);


        for (auto car :obj) {
            double carY = car->getObjbox()->centralpos.second;
            double diff = centralpos.second - carY;
            if (carToMoveFor == nullptr and carY > centralpos.second and abs(diff) <= 0.8) {
                carToMoveFor = car;
            }
            if (carToMoveFor != nullptr) {
                double carToMoveForY = carToMoveFor->getObjbox()->centralpos.second;

                if (carY > centralpos.second and carY < carToMoveForY and abs(diff) <= 0.8) {
                    carToMoveFor = car;
                }
            }
        }

        if (carToMoveFor != nullptr) {
            double carToMoveForX = carToMoveFor->getObjbox()->centralpos.first;
            double diffX = centralpos.first - carToMoveForX;
            if (abs(diffX) <= 0.2)
                if (carToMoveForX <= centralpos.first) {
                    movement = "right";
                } else if (carToMoveForX >= centralpos.first) {
                    movement = "left";
                }
        } else {
            movement = "";
        }

        if (abs(sidemovement) <= 0.3) {
            if (movement == "left") {
                if (centralpos.first > -1.84) {
                    centralpos.first = centralpos.first - 0.06;
                    sidemovement = sidemovement - 0.06;
                }
            } else if (movement == "right") {
                if (centralpos.first < -0.07) {
                    centralpos.first = centralpos.first + 0.06;
                    sidemovement = sidemovement + 0.06;
                }
            }
        } else {
        }
    }
    roadfighter::AIRacer::update();
}

int roadfighter::AIRacer::getCarTravelledDistance() const {
    return CarTravelledDistance;
}
