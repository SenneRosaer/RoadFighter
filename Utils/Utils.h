//
// Created by senne on 1/5/19.
//

#ifndef ROADFIGHTER_UTILS_H
#define ROADFIGHTER_UTILS_H

#include <iostream>

/**
 * Struct for returning collision data
 */
struct ObjBox
{
        /**
         * Central position of the object
         */
        std::pair<float, float> centralpos;

        /**
         * Height of the object
         */
        double height;

        /**
         * width of the object
         */
        double width;

        /**
         * Constructor
         * @param centralpos
         * @param height
         * @param width
         */
        ObjBox(const std::pair<float, float>& centralpos, double height, double width)
            : centralpos(centralpos), height(height), width(width)
        {
        }
};

#endif // ROADFIGHTER_UTILS_H
