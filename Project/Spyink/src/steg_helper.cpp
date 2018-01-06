#include <iostream>

#include "headers/steg_helper.h"
#include "headers/bits.h"

bool able_to_store(w_uint image_size, w_uint input_size)
{
	w_uint numBits = image_size * 2; // # num bits that the image can hold
	bool ret = false;

	if ((input_size * 8) < numBits){
		ret = true;
	}
	return ret;
}

// stores size bytes from dataToStore inside bmpImageBuffer
void store_in_image(byte *image_buffer, byte *input_buffer, w_uint size)
{
	unsigned int curByteBmp = 0, curBitBmp = 0;
	unsigned int curByteHide = 0, curBitHide = 0;
	Word mask = 0, bit = 0;
	std::cout << "Size embed: " << size << std::endl;
	if (image_buffer != NULL && input_buffer != NULL){
		for (curByteHide = 0; curByteHide < size; curByteHide++){ // loop through the text document
			// curBitBmp = 0; this produces a bug - if curBitBmp = 2 when inner loop finishes, it is reset to 0 which doesn't increment the next byte in the bmp image
			for (curBitHide = 0; curBitHide < NUM_BITS_WORD; curBitHide++){ // loop through the individual bits of each byte in the text document
				mask = 1;
				mask <<= curBitHide;
				bit = input_buffer[curByteHide] & mask; // extract a bit from a byte of the text document

				if (curBitBmp > 1){ // only hide the text bits in the 2 LSB's (least significant bits)
					curBitBmp = 0;
					curByteBmp++; // go to the next byte in the bmp file
				}

				if (bit){ // turn on a bit in a byte of the BMP
					setBit((Word *) &image_buffer[curByteBmp], curBitBmp);
				}

				else{ // turn off a bit in a byte of the BMP
					unsetBit((Word *) &image_buffer[curByteBmp], curBitBmp);
				}

				curBitBmp++;
			} // end of inner for loop
		} // end of outer for loop
	}
}
