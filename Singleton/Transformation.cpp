//
// Created by senne on 12/15/18.
//

#include "Transformation.h"


std::pair<float, float> Transformation::Transform(std::pair<float, float> input) {
    std::pair<float,float> result;
    float x = input.first;
    x = x+ 4;
    x = x/8;
    float resultx = x*Screensize.first;

    float y = input.second;
    y = y -3;
    y = y/(-6);
    float resulty = y*Screensize.second;

    return {resultx,resulty};
}


void Transformation::setScreensize(const std::pair<int, int> &Screensize) {
    Transformation::Screensize = Screensize;
}

