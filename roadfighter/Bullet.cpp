//
// Created by senne on 1/16/19.
//

#include "Bullet.h"

void roadfighter::Bullet::update(int speed) {
    int relativespeed = this->speed - speed;
    if(relativespeed < 0){
        pos.second = pos.second - 0.01* abs(relativespeed)/10;
    } else {
        pos.second = pos.second + 0.01* abs(relativespeed)/10;
    }

    if(pos.second < -3.2){
        toDel = true;
    } else if(pos.second > 3.5){
        toDel = true;
    }
}

void roadfighter::Bullet::update() {

}

int roadfighter::Bullet::getSpeed() {
    return 0;
}

bool roadfighter::Bullet::Delete() {
    return toDel;
}

void roadfighter::Bullet::setDelete(bool del) {
    toDel = del;
}

ObjBox roadfighter::Bullet::getObjBox() {
    return ObjBox({0,0}, 0, 0);
}

std::shared_ptr<ObjBox> roadfighter::Bullet::getObjbox() {
    return std::make_shared<ObjBox>(pos,0,0);
}

bool roadfighter::Bullet::Shoot() {
    return false;
}
