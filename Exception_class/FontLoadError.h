//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_FONTLOADERROR_H
#define ROADFIGHTER_FONTLOADERROR_H


#include "FileError.h"

class FontLoadError: public FileError {
private:
    const char* errorString = "Error while loading font -> ";
public:
    const char* what() const noexcept override;

    FontLoadError(const char *file);

    const char* filePath() const noexcept override;

};


#endif //ROADFIGHTER_FONTLOADERROR_H
