//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_JSONPARSEERROR_H
#define ROADFIGHTER_JSONPARSEERROR_H


#include "GameError.h"
#include "FileError.h"

class JSONParseError : public FileError {
public:
    JSONParseError(const char *file);

    const char* what() const noexcept override;

    const char* filePath() const noexcept override;

private:
    const char* ErrorString = "Error while parsing json file -> ";


};


#endif //ROADFIGHTER_JSONPARSEERROR_H
