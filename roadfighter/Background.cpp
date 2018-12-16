//
// Created by senne on 12/16/18.
//

#include "Background.h"

void roadfighter::Background::update() {
    //TODO met speed player aanpassen
    centralpos1.second = centralpos1.second - 0.1;
    centralpos2.second = centralpos2.second - 0.1;

    if(centralpos1.second <= -5.9){
        centralpos1.second = 6;
    }
    if(centralpos2.second <= -5.9){
        centralpos2.second = 6;
    }

}
