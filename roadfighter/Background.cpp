//
// Created by senne on 12/16/18.
//

#include "Background.h"

void roadfighter::Background::update() {


}

void roadfighter::Background::update(int speed) {
    //TODO met speed player aanpassen
    float movement = 0.01 * speed/10;
    centralpos1.second = centralpos1.second - movement;
    centralpos2.second = centralpos2.second - movement;
    centralpos3.second = centralpos3.second - movement;


    if(centralpos1.second <= -5.9){
        centralpos1.second = 6;
    }
    if(centralpos2.second <= -5.9){
        centralpos2.second = 6;
    }
    if(centralpos3.second <= -5.9){
        centralpos3.second = 6;
    }

}

int roadfighter::Background::getSpeed() {
    return 0;
}
