//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_SCOREERROR_H
#define ROADFIGHTER_SCOREERROR_H


#include "GameError.h"

/**
 * Error that appears when there is a fault with the score
 */
class ScoreError: public GameError {
private:
    const char* errorString = "Negative score";
public:
    const char* what() const noexcept override;


};


#endif //ROADFIGHTER_SCOREERROR_H
