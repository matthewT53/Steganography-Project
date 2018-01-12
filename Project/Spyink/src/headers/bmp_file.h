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

        // no need for destructor, just destroy the base class then we're done

        // hides another file in this BMP image.
        virtual void hide(const std::string &input_filename, const std::string &password) const;

        // reveals a file hidden inside this BMP image.
        virtual void reveal(const std::string &output_filename, const std::string &password) const;

        // returns the image's height
        int get_height() const;

        // returns the image's width
        int get_width() const;

    private:
        int height_;
        int width_;

        static int header_size_; // size of the bmp header
};

#endif
