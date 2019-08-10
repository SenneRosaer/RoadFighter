//
// Created by sennerosaer on 8/10/19.
//

#include "FontLoadError.h"

const char *FontLoadError::what() const noexcept {
    return errorString;
}
