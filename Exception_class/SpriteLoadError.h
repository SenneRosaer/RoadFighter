//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_SPRITELOADERROR_H
#define ROADFIGHTER_SPRITELOADERROR_H


#include "FileError.h"

class SpriteLoadError : public FileError {
private:
    const char* errorString = "Error while loading sprite -> ";
public:
    SpriteLoadError(const char *file);

    const char* what() const noexcept override;

    const char* filePath() const noexcept override;
};


#endif //ROADFIGHTER_SPRITELOADERROR_H
