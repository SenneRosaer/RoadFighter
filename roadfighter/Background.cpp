//
// Created by senne on 12/16/18.
//

#include "Background.h"

void roadfighter::Background::update() {}

void roadfighter::Background::update(int speed, std::shared_ptr<roadfighter::Entity> Player)
{

        // If one of the backgrounds has moved below the screen we can move it to the back of the last one so it keeps
        // going
        double movement = 0.01 * speed / 10;
        centralpos1.second = centralpos1.second - movement;
        centralpos2.second = centralpos2.second - movement;
        centralpos3.second = centralpos3.second - movement;
        if (moveFinish) {
                centralposfin.second = centralposfin.second - movement;
        }

        if (centralpos1.second <= -9) {
                centralpos1.second = centralpos3.second + 6;
        }
        if (centralpos2.second <= -9) {
                centralpos2.second = centralpos1.second + 6;
        }
        if (centralpos3.second <= -9) {
                centralpos3.second = centralpos2.second + 6;
        }

        CarTravelledDistance = CarTravelledDistance + speed;
}

int roadfighter::Background::getSpeed() { return 0; }

int roadfighter::Background::Delete() { return toDel; }

std::shared_ptr<ObjBox> roadfighter::Background::getObjbox() { return std::shared_ptr<ObjBox>(); }

void roadfighter::Background::setDelete(int del) { toDel = del; }

bool roadfighter::Background::Shoot() { return false; }

roadfighter::Background::Background(std::shared_ptr<ConfigData> config) { roadfighter::Entity::Config = config; }
