//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_FILEERROR_H
#define ROADFIGHTER_FILEERROR_H


#include "GameError.h"

class FileError: public GameError {
protected:
    const char* file;
public:
     FileError(const char *file);

    virtual const char* filePath() const noexcept = 0;


};


#endif //ROADFIGHTER_FILEERROR_H
