/*
    Author: Matthew Ta
    Date: 6/01/2018
    Description: This file contains helper functions for performing steganography.
*/

#ifndef STEG_HELPER_H
#define STEG_HELPER_H

#include <string>

typedef unsigned char byte;
typedef unsigned int w_uint;

// stores the bits of an input file into an image buffer
void store_in_image(byte *image_buffer, byte *input_buffer, w_uint size);

// determines if the input file will fit into the media file
bool able_to_store(w_uint image_size, w_uint input_size); // determines if we are able to store a file in an image

// extracts the hidden data and stores it in the output buffer
void extract_bits(byte *image_buffer, byte *output_buffer, w_uint num_bytes);

// stores the contents of output_buffer onto a file on the disk
void write_to_file(char *output_buffer, w_uint size, std::string output_filename);

#endif
