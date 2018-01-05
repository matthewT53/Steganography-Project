#include <iostream>
#include <string>

#include "headers/bmp.h"

BMPFile::BMPFile(const std::string &bmp_filename)
: StegFile(bmp_filename)
{
    // empty constructor
}

void BMPFile::hide(StegFile &f) const
{
    std::cout << "Hiding file: " << f.get_file_name() << std::endl;
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
