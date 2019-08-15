//
// Created by sennerosaer on 8/10/19.
//

#ifndef ROADFIGHTER_FONTLOADERROR_H
#define ROADFIGHTER_FONTLOADERROR_H


#include "FileError.h"

/**
 * Error that appears when failing to load a font
 */
class FontLoadError: public FileError {
private:
    const char* errorString = "Error while loading font -> ";
public:
    /**
     * Return the error message
     * @return
     */
    const char* what() const noexcept override;

    /**
     * Constructor with the file that caused the error
     * @param file
     */
    FontLoadError(const char *file);

    /**
     * return the file that caused the error
     * @return
     */
    const char* filePath() const noexcept override;

};


#endif //ROADFIGHTER_FONTLOADERROR_H
