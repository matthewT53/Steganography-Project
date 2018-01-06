/*
    Author: Matthew Ta
    Date: 6/01/2018
    Description: This file contains helper functions for performing steganography
*/

#ifndef STEG_HELPER_H
#define STEG_HELPER_H

typedef unsigned char byte;
typedef unsigned int w_uint;

// stores the bits of an input file into an image buffer
void store_in_image(byte *image_buffer, byte *input_buffer, w_uint size);

// determines if the input file will fit into the media file
bool able_to_store(w_uint image_size, w_uint input_size); // determines if we are able to store a file in an image

#endif
