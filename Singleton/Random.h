//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_RANDOM_H
#define ROADFIGHTER_RANDOM_H

#include <iostream>
#include <vector>

class Random
{
public:
        static Random& getInstance()
        {
                static Random instance;
                return instance;
        }

        /**
         *  Returns a random value of the positions vector
         * @return double
         */
        double getRandom();
        double getRandom2();
       double getRandom3();
       int getRandom4();


private:
        // Vector with positions to choose from TODO Set correct pos
        std::vector<double> positions{-0.1, -1.6, -1, -0.7};
    std::vector<double> positionsRock{-1.86,-1.38,-0.3,-0.9};

    Random(){};
        Random(Random const&);
        Random operator=(Random const&);
};

#endif // ROADFIGHTER_RANDOM_H
