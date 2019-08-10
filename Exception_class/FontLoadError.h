//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_FONTLOADERROR_H
#define ROADFIGHTER_FONTLOADERROR_H


#include "GameError.h"

class FontLoadError: public GameError {
private:
    const char* errorString = "Error while loading font";
public:
    const char* what() const noexcept override;

};


#endif //ROADFIGHTER_FONTLOADERROR_H
