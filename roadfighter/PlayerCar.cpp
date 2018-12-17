//
// Created by senne on 12/15/18.
//

#include "PlayerCar.h"


void roadfighter::PlayerCar::move(std::string input) {
    //TODO fix lim muren
    if(input == "left"){
        if(centralpos.first > - 1.861) {
            centralpos.first = centralpos.first - 0.07;
        }
    }
    else if (input == "right"){
        if(centralpos.first < -0.065) {
            centralpos.first = centralpos.first + 0.07;
        }
    }
}


void roadfighter::PlayerCar::UpdateMovement(std::vector<std::string> inputs) {
    bool speed = false;
    bool breaking = false;
    for (int i = 0; i < inputs.size(); i++) {
        if(inputs[i] == "up"){
            if(this->speed < 200) {
                this->speed = this->speed + 2;
                speed = true;
            }
        } else {
            move(inputs[i]);
        }
        if(inputs[i] == "down"){
            breaking = true;
        }
    }

    if(!speed){
        if(this->speed >= 0) {
            if(breaking){
                this->speed = this->speed - 2;
            } else {
                this->speed = this->speed - 1;
            }
        }
        if(this->speed < 0){
            this->speed = 0;
        }
    }

}

void roadfighter::PlayerCar::update(int speed) {

}

int roadfighter::PlayerCar::getSpeed() {
    return speed;
}

