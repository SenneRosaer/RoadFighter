//
// Created by sennerosaer on 8/10/19.
//

#include "JSONParseError.h"

JSONParseError::JSONParseError(const char *file) : FileError(file) {}

const char *JSONParseError::what() const noexcept {
    return ErrorString;
}

const char* JSONParseError::filePath() const noexcept {
    return file;
}
