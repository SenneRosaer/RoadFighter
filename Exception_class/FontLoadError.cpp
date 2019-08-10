//
// Created by sennerosaer on 8/10/19.
//

#include "FontLoadError.h"

const char *FontLoadError::what() const noexcept {
    return errorString;
}

FontLoadError::FontLoadError(const char *file) : FileError(file) {}

const char* FontLoadError::filePath() const noexcept {
    return file;
}
