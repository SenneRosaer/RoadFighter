//
// Created by sennerosaer on 7/22/19.
//

#include "Rock.h"

void roadfighter::Rock::update(int speed, std::shared_ptr<roadfighter::Entity> Player){
    int relativespeed = this->speed - speed;
    if (relativespeed < 0) {
        centralpos.second = centralpos.second - 0.01 * abs(relativespeed) / 10;
    } else {
        centralpos.second = centralpos.second + 0.01 * abs(relativespeed) / 10;
    }

    if (centralpos.second < -3.2) {
        toDel = true;
    } else if (centralpos.second > 3.5) {
        toDel = true;
    }

}

void roadfighter::Rock::update() {

}

int roadfighter::Rock::getSpeed() {
    return 0;
}

int roadfighter::Rock::Delete() {
    return toDel;
}

void roadfighter::Rock::setDelete(int del) {
    toDel = del;
}

std::shared_ptr<ObjBox> roadfighter::Rock::getObjbox() {
    return std::make_shared<ObjBox>(centralpos, height, width);
}


bool roadfighter::Rock::Shoot() {
    return false;
}
