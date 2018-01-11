#include <iostream>

#include "headers/png_file.h"
#include "headers/lodepng.h"
#include "headers/steg_helper.h"

PNGFile::PNGFile(const std::string &filename)
: StegFile(filename)
{
    std::cout << "Getting image data." << std::endl;
    // need to allocate memory for image_data_
    w_uint error_code = lodepng_decode24(image_data_, &width_, &height_, StegFile::buffer_, StegFile::get_file_size());
    std::cout << "Finished getting data." << std::endl;
    if (error_code){
        std::cout << "Error loading png image data." << std::endl;
    }
}

void PNGFile::hide(const std::string &input_filename, const std::string &password) const
{
    std::cout << "Hiding in PNG image." << std::endl;
}

void PNGFile::reveal(const std::string &output_filename, const std::string &password) const
{
    std::cout << "Revealing what was hidden in this PNG image." << std::endl;
}

w_uint PNGFile::get_height() const
{
    return height_;
}

w_uint PNGFile::get_width() const
{
    return width_;
}
