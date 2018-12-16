//
// Created by senne on 12/15/18.
//

#include "PlayerCar.h"


void roadfighter::PlayerCar::move(std::string input) {
    if(input == "left"){
        centralpos.first = centralpos.first - 0.08;
    }
    else if (input == "right"){
        centralpos.first = centralpos.first + 0.08;
    }
}


void roadfighter::PlayerCar::UpdateMovement(std::vector<std::string> inputs) {
    bool speed = false;
    bool breaking = false;
    for (int i = 0; i < inputs.size(); i++) {
        if(inputs[i] == "up"){
            if(this->speed < 400) {
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
        if(this->speed > 0) {
            if(breaking){
                this->speed = -2;
            } else {
                this->speed = this->speed - 1;
            }
        }
    }
}

