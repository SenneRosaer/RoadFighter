//
// Created by sennerosaer on 8/10/19.
//

#include "ScoreError.h"

const char* ScoreError::what() const noexcept {
    return errorString;
}
