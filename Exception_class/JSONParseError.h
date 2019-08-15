//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_JSONPARSEERROR_H
#define ROADFIGHTER_JSONPARSEERROR_H


#include "GameError.h"
#include "FileError.h"

/**
 * Error that appears when there is a mistake while parsing or loading a json file
 */
class JSONParseError : public FileError {
public:
    /**
     * Constructor with file that contained the error
     * @param file
     */
    JSONParseError(const char *file);

    /**
     * Returns the error message
     * @return
     */
    const char* what() const noexcept override;

    /**
     * Returns the file that caused the erro
     * @return
     */
    const char* filePath() const noexcept override;

private:
    const char* ErrorString = "Error while parsing json file -> ";


};


#endif //ROADFIGHTER_JSONPARSEERROR_H
