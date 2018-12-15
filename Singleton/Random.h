//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_RANDOM_H
#define ROADFIGHTER_RANDOM_H


class Random {
public:
    static Random& getInstance()
    {
        static Random instance;
        return instance;
    }


    int getRandom();

private:
    Random(){};
    Random(Random const&);
    Random operator=(Random const&);
};


#endif //ROADFIGHTER_RANDOM_H
