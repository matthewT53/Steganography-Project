#include <iostream>
#include <string>
#include <fstream>

#include "headers/bmp.h"
#include "headers/steg_helper.h"
#include "headers/bin_file.h"

BMPFile::BMPFile(const std::string &bmp_filename)
: StegFile(bmp_filename)
{
    unsigned char buffer[4] = {0};
    int i = 0;

    // extract the width
    for (i = 0; i < 4; i++){
        buffer[i] = StegFile::buffer_[18 + i]; // width is at an offset of 18 bytes
    }

    width_ = (buffer[0] << 0) | (buffer[1] << 8) | (buffer[2] << 16) | (buffer[3] << 24);

    // extract the height
    for (i = 0; i < 4; i++){
        buffer[i] = StegFile::buffer_[22 + i]; // height is after width
    }

    height_ = (buffer[0] << 0) | (buffer[1] << 8) | (buffer[2] << 16) | (buffer[3] << 24);
}

void BMPFile::hide(const std::string &input_filename, const std::string &password) const
{
    std::cout << "Hiding file: " << input_filename << std::endl;

    BinFile bin(input_filename);

    
}

void BMPFile::reveal(const std::string &output_filename, const std::string &password) const
{
    std::cout << "Revealing file: " << output_filename << std::endl;
}

int BMPFile::get_height() const
{
    return height_;
}

int BMPFile::get_width() const
{
    return width_;
}
