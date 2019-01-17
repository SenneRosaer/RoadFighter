//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_RANDOM_H
#define ROADFIGHTER_RANDOM_H

#include <iostream>
#include <vector>

class Random {
public:
    static Random& getInstance()
    {
        static Random instance;
        return instance;
    }


    double getRandom();

private:
    //Vector with positions to choose from TODO Set correct pos
    std::vector<double> positions {-0.1,-1.6,-1,-0.7};
    Random(){};
    Random(Random const&);
    Random operator=(Random const&);
};


#endif //ROADFIGHTER_RANDOM_H
