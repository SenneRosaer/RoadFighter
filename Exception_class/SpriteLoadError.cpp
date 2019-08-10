//
// Created by sennerosaer on 8/10/19.
//

#include "SpriteLoadError.h"

const char* SpriteLoadError::what() const noexcept {
    return errorString;
}
