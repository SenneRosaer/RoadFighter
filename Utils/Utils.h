//
// Created by senne on 1/5/19.
//

#ifndef ROADFIGHTER_UTILS_H
#define ROADFIGHTER_UTILS_H


#include <iostream>

struct ObjBox {
    std::pair<float,float> centralpos;
    double height;
    double width;

    ObjBox(const std::pair<float, float> &centralpos, double height, double width) : centralpos(centralpos),
                                                                                     height(height), width(width) {}
};

#endif //ROADFIGHTER_UTILS_H
