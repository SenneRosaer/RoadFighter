//
// Created by senne on 12/15/18.
//

#include "PlayerCar.h"

void roadfighter::PlayerCar::move(std::string input)
{
        // TODO fix lim muren
        if (!finished) {
                if (!disableActions) {
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
}

void roadfighter::PlayerCar::UpdateMovement(std::vector<std::string> inputs)
{
        // Update action acording to inputs
        // Shoot if space or move up, break, left, right
        // Only possible if we are not in bossfight or respawning
        if (!disableActions) {
                bool speed = false;
                bool breaking = false;
                if (reloading) {
                        shoot = false;
                        if (reload >= 1) {
                                reload--;
                        } else {
                                reload = reloadval;
                                reloading = false;
                        }
                }
                if (!finished) {
                        for (int i = 0; i < inputs.size(); i++) {
                                if (inputs[i] == "up") {
                                        if (!bossfight) {
                                                if (this->speed < maxSpeed) {
                                                        this->speed = this->speed + acceleration;
                                                        speed = true;
                                                }
                                        }
                                } else {
                                        // We can move left or right during bossfight
                                        move(inputs[i]);
                                }
                                if (!bossfight) {
                                        if (inputs[i] == "down") {
                                                breaking = true;
                                        }
                                }
                                if (!disableActions) {
                                        if (inputs[i] == "space" && !reloading) {
                                                shoot = true;
                                                reloading = true;
                                        }
                                }
                        }

                        if (!speed) {
                                if (!bossfight) {
                                        if (this->speed >= 0) {
                                                if (breaking) {
                                                        this->speed = this->speed - acceleration * 2;
                                                } else {
                                                        this->speed = this->speed - acceleration;
                                                }
                                        }
                                        if (this->speed < 0) {
                                                this->speed = 0;
                                        }
                                }
                        }
                } else {
                        if (!bossfight) {
                                if (this->speed >= 0) {
                                        this->speed = this->speed - acceleration * 2;
                                }
                                if (this->speed < 0) {
                                        this->speed = 0;
                                }
                        }
                }
        }
}

void roadfighter::PlayerCar::update(int speed, std::shared_ptr<roadfighter::Entity> Player) {}

int roadfighter::PlayerCar::getSpeed() { return speed; }

int roadfighter::PlayerCar::Delete() { return toDel; }

std::shared_ptr<ObjBox> roadfighter::PlayerCar::getObjbox()
{
        return std::make_shared<ObjBox>(centralpos, height, width);
}

void roadfighter::PlayerCar::setDelete(int del) { toDel = del; }

bool roadfighter::PlayerCar::Shoot() { return shoot; }

void roadfighter::PlayerCar::update()
{
        // Set finished if it is not the last level
        CarTravelledDistance = CarTravelledDistance + speed;
        if (CarTravelledDistance > roadfighter::Entity::Config->getDistance()) {
                if (level != 3) {
                        finished = true;
                }
        }

        // 2 is for respawning the car
        if (toDel == 2) {
                speed = 0;
                respawntimer--;
                disableActions = true;
                shoot = false;
                if (respawntimer <= 0) {
                        toDel = 0;
                        respawntimer = respawntimerVal;
                        disableActions = false;
                }
        }

        // Initiate boss fight if it is the third level
        if (level == 3 and CarTravelledDistance > roadfighter::Entity::Config->getDistance()) {
                speed = roadfighter::Entity::Config->getBossfightSpeed();
                bossfight = true;

                finished = false;
        }
}

roadfighter::PlayerCar::PlayerCar(std::shared_ptr<ConfigData> config)
{
        roadfighter::Entity::Config = config;
        reload = config->getReloadSpeed();
        reloadval = reload;
        respawntimer = config->getRespawnTimerPlayer();
        respawntimerVal = respawntimer;
        acceleration = config->getAccelerationPlayer();
        maxSpeed = config->getMaxSpeedPlayer();
}
