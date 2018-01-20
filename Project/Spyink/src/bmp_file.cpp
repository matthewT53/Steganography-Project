#include <iostream>
#include <string>
#include <vector>

#include "headers/bmp_file.h"
#include "headers/steg_helper.h"
#include "headers/bin_file.h"

int BMPFile::header_size_ = 54;
std::vector<Byte> BMPFile::signature_ = {0x42, 0x4D}; // BM

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
    byte size_buffer[4] = {0};
    w_uint input_size = bin.get_file_size();

    std::cout << "Hiding file: " << input_filename << std::endl;
    std::cout << "Size: " << input_size << std::endl;

    // check if our input file will fit into this BMP image.
    if (able_to_store(get_file_size(), input_size)){
        // store the size of the input file
        size_buffer[0] = 0x000000FF & input_size;
        size_buffer[1] = (0x0000FF00 & input_size) >> 8;
        size_buffer[2] = (0x00FF0000 & input_size) >> 16;
        size_buffer[3] = (0xFF000000 & input_size) >> 24;
        store_in_image((StegFile::buffer_ + header_size_), size_buffer, 4);

        // store the input file
        // an int is 32 bits and each byte takes 2 of these bits so 16 bytes are required.
        store_in_image((StegFile::buffer_ + header_size_ + 16), reinterpret_cast<byte *>(bin.get_buffer()), bin.get_file_size());

        // write the new file containing the hidden file to disk
        write_to_file(StegFile::buffer_, get_file_size(), get_file_name() + "_hidden");

        std::cout << "Finished hiding file." << std::endl;
    }
}

void BMPFile::reveal(const std::string &output_filename, const std::string &password) const
{
    std::cout << "Revealing file: " << output_filename << std::endl;
    byte size_buffer[4] = {0};
    w_uint output_size = 0;

    // extract the size of the hidden file
    extract_bits(reinterpret_cast<byte *>(StegFile::buffer_ + header_size_), size_buffer, 4);
    output_size |= static_cast<w_uint>(size_buffer[0]);
    output_size |= static_cast<w_uint>(size_buffer[1]) << 8;
    output_size |= static_cast<w_uint>(size_buffer[2]) << 16;
    output_size |= static_cast<w_uint>(size_buffer[3]) << 24;

    std::cout << "Hidden file size: " << output_size << std::endl;

    // extract the hidden file into a buffer
    char *output_buffer = new char[output_size + 5]; // extra room

    // clear the buffer first
    for (int i = 0; i < static_cast<int>(output_size); i++){
        output_buffer[i] = 0;
    }

    extract_bits(reinterpret_cast<byte *>(StegFile::buffer_ + header_size_ + 16), (byte *)output_buffer, output_size);

    // write buffer to file
    write_to_file(reinterpret_cast<byte *>(output_buffer), output_size, output_filename + "_revealed");

    delete [] output_buffer;
}

int BMPFile::get_height() const
{
    return height_;
}

int BMPFile::get_width() const
{
    return width_;
}
