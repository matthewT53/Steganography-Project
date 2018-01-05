/*
    Author: Matthew Ta
    Date: 5/1/2018
    BMP file class which implements the abstract File class.
*/

#ifndef BMP_H
#define BMP_H

#include <string>

#include "file.h"

class BMPFile : public File
{
    public:
        // constructor
        BMPFile(const std::string bmp_filename);

        // hides another file in this BMP image
        virtual void hide(File &f);

        // returns image dimensions
        

    private:

};

#endif
