#include <iostream>

#include "headers/png_file.h"
#include "headers/lodepng.h"
#include "headers/steg_helper.h"

PngFile::PngFile(const std::string &filename)
: StegFile(filename)
{
    w_uint error_code = lodepng_decode24(image_data_, &width_, &height_, StegFile::buffer_, StegFile::get_file_size());
    if (error_code){
        std::cout << "Error loading png image data." << std::endl;
    }
}

void PngFile::hide(const std::string &input_filename, const std::string &password) const
{
    
}

void PngFile::reveal(const std::string &output_filename, const std::string &password) const
{

}

w_uint PngFile::get_height() const
{
    return height_;
}

w_uint PngFile::get_width() const
{
    return width_;
}
