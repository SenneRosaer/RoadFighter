//
// Created by sennerosaer on 8/8/19.
//

#include "Boss.h"
#include "../Singleton/Random.h"

void roadfighter::Boss::update() {

}

void roadfighter::Boss::update(int speed, std::shared_ptr<roadfighter::Entity> Player) {
    if (centralpos.second > 2.4) {
        currentspeed = Startspeed;
        centralpos.second = centralpos.second - 0.02;

    } else {
        currentspeed = endSpeed;
        if (move == "left") {
            if (centralpos.first > -1.84) {
                centralpos.first = centralpos.first - 0.03;
                if (centralpos.first > -1.84 and centralpos.first < -1.67) {
                    move = "right";
                }
            }
        }
        if (move == "right") {


            if (centralpos.first < -0.07) {
                centralpos.first = centralpos.first + 0.03;
                if(centralpos.first < -0.07 and centralpos.first > -0.17){
                    move = "left";
                }
            }
        }

    }

    if(attackTimer == 0){
        attackTimer = 60;
        std::vector<double> allRockPos = {-1.86,-1.38,-0.3,-0.9};
        int random = Random::getInstance().getRandom4();

        allRockPos.erase(allRockPos.begin() + random);
        rockPos = allRockPos;
        getRocks = true;
    } else {
        attackTimer--;
    }


}

const std::vector<double> &roadfighter::Boss::getRockPos() const {
    return rockPos;
}

int roadfighter::Boss::getSpeed() {
    return currentspeed;
}

int roadfighter::Boss::Delete() {
    return toDel;
}

void roadfighter::Boss::setDelete(int del) {
    toDel = del;
}

bool roadfighter::Boss::Shoot() {
    return false;
}

std::shared_ptr<ObjBox> roadfighter::Boss::getObjbox() {
    return std::make_shared<ObjBox>(centralpos, height, width);
}

bool roadfighter::Boss::isGetRocks() const {
    return getRocks;
}

void roadfighter::Boss::setGetRocks(bool getRocks) {
    Boss::getRocks = getRocks;
}

int roadfighter::Boss::getLife() const {
    return life;
}

void roadfighter::Boss::setLife(int life) {
    Boss::life = life;
}
