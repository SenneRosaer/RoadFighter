//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_FILEERROR_H
#define ROADFIGHTER_FILEERROR_H


#include "GameError.h"

/**
 * class that acts as parent class for errors that occur when loading or using files
 */
class FileError: public GameError {
protected:
    /**
     * File that caused the error
     */
    const char* file;
public:
    /**
     * Constructor for a file error with the file that caused the error
     * @param file
     */
     FileError(const char *file);

     /**
      * Return the file that caused the error
      * @return
      */
    virtual const char* filePath() const noexcept = 0;


};


#endif //ROADFIGHTER_FILEERROR_H
