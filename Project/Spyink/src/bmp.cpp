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
    BinFile bin(input_filename);
    std::fstream output_file(get_file_name() + "_out", std::ios::binary | std::ios::out);

    std::cout << "Hiding file: " << input_filename << std::endl;

    // check if our input file will fit into this BMP image.
    if (able_to_store(get_file_size(), bin.get_file_size())){
        store_in_image((byte *)StegFile::buffer_, (byte *)BinFile::StegFile::buffer_, bin.get_file_size());

        if (output_file.is_open()){
            output_file.write(StegFile::buffer_, get_file_size());
            output_file.close();
        }

        std::cout << "Finished hiding file." << std::endl;
    }
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
