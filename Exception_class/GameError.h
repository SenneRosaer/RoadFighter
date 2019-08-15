//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_GAMEERROR_H
#define ROADFIGHTER_GAMEERROR_H

#include "iostream"


/**
 * Base exception class for errors in the game
 */
class GameError: public std::exception {
public:
    /**
     * Return the error message
     * @return
     */
    virtual const char* what() const noexcept = 0;
};


#endif //ROADFIGHTER_GAMEERROR_H
