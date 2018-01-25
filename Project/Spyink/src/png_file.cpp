#include <iostream>
#include <vector>

#include "headers/png_file.h"
#include "headers/lodepng.h"
#include "headers/steg_helper.h"
#include "headers/bin_file.h"
#include "headers/protect.h"

std::vector<Byte> PNGFile::signature_ = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};

PNGFile::PNGFile(const std::string &filename)
: StegFile(filename)
{
    std::cout << "Getting image data." << std::endl;
    // need to allocate memory for image_data_
    image_data_ = new Byte[5]; // size doesn't matter, the function below resizes this buffer

    w_uint error_code = lodepng_decode24(&image_data_, &width_, &height_, StegFile::buffer_, StegFile::get_file_size());
    std::cout << "Finished getting data." << std::endl;
    if (error_code){
        std::cout << "Error loading png image data." << std::endl;
    }
}

PNGFile::~PNGFile()
{
    // free the image data
    delete [] image_data_;
}

void PNGFile::hide(const std::string &input_filename, const std::string &password, bool do_encrypt) const
{
    BinFile bin(input_filename);
    byte size_buffer[4] = {0};
    w_uint input_size = bin.get_file_size();
    w_uint image_data_size = width_ * height_ * 3;
    int padding_len = 0;

    std::cout << "Hiding in PNG image." << std::endl;
    std::cout << "Hiding file: " << input_filename << std::endl;
    std::cout << "Size: " << input_size << std::endl;

    Byte *input_buffer = bin.get_buffer();
    if (do_encrypt){
        if (input_size % 16 != 0){
            padding_len = (16 - (input_size % 16));
            w_uint new_size = input_size + padding_len;
            Byte *new_buffer = new Byte[new_size];

            std::copy(input_buffer, input_buffer + input_size, new_buffer);

            input_buffer = new_buffer;
            input_size = new_size;

            add_padding(input_buffer, input_size, padding_len);
            // no need to free input_buffer since the destructor will do the job for us
        }

        encrypt(input_buffer, input_size, password);
    }

    if (able_to_store(image_data_size, input_size)){
        // store the size of the input file
        size_buffer[0] = 0x000000FF & input_size;
        size_buffer[1] = (0x0000FF00 & input_size) >> 8;
        size_buffer[2] = (0x00FF0000 & input_size) >> 16;
        size_buffer[3] = (0xFF000000 & input_size) >> 24;
        store_in_image(image_data_, size_buffer, 4);

        // store the input file
        // an int is 32 bits and each byte takes 2 of these bits so 16 bytes are required.
        store_in_image(image_data_ + 16, input_buffer, input_size);

        // write the new file containing the hidden file to disk
        w_uint error = lodepng_encode24_file(std::string(get_file_name() + "_hidden").c_str(), image_data_, width_, height_);
        if (error){
            std::cout << "Error writing png image data to disk." << std::endl;
        }

        std::cout << "Finished hiding file." << std::endl;
    }
}

void PNGFile::reveal(const std::string &output_filename, const std::string &password, bool do_decrypt) const
{
    std::cout << "Revealing what was hidden in this PNG image." << std::endl;
    byte size_buffer[4] = {0};
    w_uint output_size = 0;
    int new_size = 0;

    // extract the size of the hidden file
    extract_bits(image_data_, size_buffer, 4);
    output_size |= static_cast<w_uint>(size_buffer[0]);
    output_size |= static_cast<w_uint>(size_buffer[1]) << 8;
    output_size |= static_cast<w_uint>(size_buffer[2]) << 16;
    output_size |= static_cast<w_uint>(size_buffer[3]) << 24;

    std::cout << "Hidden file size: " << output_size << std::endl;

    // extract the hidden file into a buffer
    Byte *output_buffer = new Byte[output_size + 5]; // extra room

    // clear the buffer first
    for (int i = 0; i < static_cast<int>(output_size); i++){
        output_buffer[i] = 0;
    }

    extract_bits((image_data_ + 16), output_buffer, output_size);

    if (do_decrypt){
        decrypt(output_buffer, output_size, password);
        remove_padding(output_buffer, output_size, &new_size);
        output_size = new_size;
    }

    // write buffer to file
    write_to_file(reinterpret_cast<Byte *>(output_buffer), output_size, output_filename + "_revealed");
    delete [] output_buffer;
}

w_uint PNGFile::get_height() const
{
    return height_;
}

w_uint PNGFile::get_width() const
{
    return width_;
}
