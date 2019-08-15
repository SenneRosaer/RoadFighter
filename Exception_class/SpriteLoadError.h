//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_SPRITELOADERROR_H
#define ROADFIGHTER_SPRITELOADERROR_H


#include "FileError.h"

/**
 * Error that appears when failing to load a sprite
 */
class SpriteLoadError : public FileError {
private:
    const char* errorString = "Error while loading sprite -> ";
public:
    /**
     * Constructor with the file that caused the error
     * @param file
     */
    SpriteLoadError(const char *file);

    /**
     * Returns error message
     * @return
     */
    const char* what() const noexcept override;

    /**
     * Returns the file that caused the error
     * @return
     */
    const char* filePath() const noexcept override;
};


#endif //ROADFIGHTER_SPRITELOADERROR_H
