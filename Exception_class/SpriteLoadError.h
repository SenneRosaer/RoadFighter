//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_SPRITELOADERROR_H
#define ROADFIGHTER_SPRITELOADERROR_H


#include "GameError.h"

class SpriteLoadError : public GameError {
private:
    const char* errorString = "Error while loading sprite";
public:
    const char* what() const noexcept override;
};


#endif //ROADFIGHTER_SPRITELOADERROR_H
