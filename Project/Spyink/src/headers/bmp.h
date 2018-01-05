/*
    Author: Matthew Ta
    Date: 5/1/2018
    BMP file class which implements the abstract StegFile class.
*/

#ifndef BMP_H
#define BMP_H

#include <string>

#include "steg_file.h"

class BMPFile : public StegFile
{
    public:
        // constructor
        BMPFile(const std::string &bmp_filename);

        // hides another file in this BMP image.
        virtual void hide(StegFile &f) const;

        // reveals a file hidden inside this BMP image.
        virtual void reveal(const std::string &output_filename, const std::string &password) const;

        // returns the image's height
        int get_height() const;

        // returns the image's width
        int get_width() const;

    private:
        int height_;
        int width_;
};

#endif
