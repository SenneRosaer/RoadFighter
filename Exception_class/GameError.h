//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_GAMEERROR_H
#define ROADFIGHTER_GAMEERROR_H

#include "iostream"


class GameError: public std::exception {
public:
    virtual const char* what() const noexcept = 0;
};


#endif //ROADFIGHTER_GAMEERROR_H
