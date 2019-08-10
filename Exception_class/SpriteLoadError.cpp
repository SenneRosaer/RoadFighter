//
// Created by sennerosaer on 8/10/19.
//

#include "SpriteLoadError.h"

const char* SpriteLoadError::what() const noexcept {
    return errorString;
}


SpriteLoadError::SpriteLoadError(const char *file) : FileError(file) {}

const char* SpriteLoadError::filePath() const noexcept {
    return file;
}
