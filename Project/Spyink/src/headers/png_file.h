#ifndef PNG_FILE_H
#define PNG_FILE_H

#include <string>

#include "steg_file.h"

class PngFile : public StegFile
{
    public:
        // constructor
        PngFile(const std::string &filename);

        // 

    private:
        int height_;
        int width_;
};

#endif
