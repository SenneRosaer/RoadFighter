//
// Created by senne on 12/15/18.
//

#include "PlayerCar.h"

void roadfighter::PlayerCar::move(std::string input)
{
        // TODO fix lim muren
        if(!finished) {
            if (input == "left") {
                if (centralpos.first > -1.84) {
                    centralpos.first = centralpos.first - 0.06;
                }
            } else if (input == "right") {
                if (centralpos.first < -0.07) {
                    centralpos.first = centralpos.first + 0.06;
                }
            }
        }
}

void roadfighter::PlayerCar::UpdateMovement(std::vector<std::string> inputs)
{
        if(!disableActions) {
            bool speed = false;
            bool breaking = false;
            if (reloading) {
                shoot = false;
                if (reload >= 1) {
                    reload--;
                } else {
                    reload = 30;
                    reloading = false;
                }
            }
            if (!finished) {
                for (int i = 0; i < inputs.size(); i++) {
                    if (inputs[i] == "up") {
                        if (this->speed < 200) {
                            this->speed = this->speed + 2;
                            speed = true;
                        }
                    } else {
                        move(inputs[i]);
                    }
                    if (inputs[i] == "down") {
                        breaking = true;
                    }
                    if (inputs[i] == "space" && !reloading) {
                        shoot = true;
                        reloading = true;
                    }
                }

                if (!speed) {
                    if (this->speed >= 0) {
                        if (breaking) {
                            this->speed = this->speed - 4;
                        } else {
                            this->speed = this->speed - 1;
                        }
                    }
                    if (this->speed < 0) {
                        this->speed = 0;
                    }
                }
            } else {
                if (this->speed >= 0) {
                    this->speed = this->speed - 4;

                }
                if (this->speed < 0) {
                    this->speed = 0;
                }
            }
        }
}

void roadfighter::PlayerCar::update(int speed, std::shared_ptr<roadfighter::Entity> Player) {





}

int roadfighter::PlayerCar::getSpeed() { return speed; }

int roadfighter::PlayerCar::Delete() { return toDel; }


std::shared_ptr<ObjBox> roadfighter::PlayerCar::getObjbox()
{
        return std::make_shared<ObjBox>(centralpos, height, width);
}

void roadfighter::PlayerCar::setDelete(int del) { toDel = del; }

bool roadfighter::PlayerCar::Shoot() { return shoot; }


void roadfighter::PlayerCar::update() {
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
