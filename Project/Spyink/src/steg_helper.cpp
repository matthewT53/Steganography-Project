#include <iostream>
#include <fstream>
#include <vector>

#include "headers/steg_helper.h"
#include "headers/bits.h"

// #define DEBUG

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
			// std::cout << "Byte: ";
			for (curBitHide = 0; curBitHide < NUM_BITS_WORD; curBitHide++){ // loop through the individual bits of each byte in the text document
				mask = 1;
				mask <<= curBitHide;
				bit = input_buffer[curByteHide] & mask; // extract a bit from a byte of the text document

				//	std::cout << ((bit) ? 1 : 0);

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

		//	std::cout << std::endl;
		} // end of outer for loop
	}
}

void extract_bits(byte *image_buffer, byte *output_buffer, w_uint num_bytes)
{
	unsigned int curByte = 0, cbit = 0, imageByte = 0;
	Word mask1 = 1, mask2 = 1;
	Word bit1 = 0, bit2 = 0;

	if (image_buffer != NULL && output_buffer != NULL){
		for (curByte = 0; curByte < num_bytes; curByte++){ // loop though buffer
			// showBits(&buffer[curByte]);
			for (cbit = 0; cbit < NUM_BITS_WORD; cbit += 2){ // extract two bits at a time
				mask1 = 1;
				mask2 = 1;
				// extract the two least sig bits from each byte in the image
				mask1 <<= 0;
				mask2 <<= 1;

				bit1 = mask1 & image_buffer[imageByte];
				bit2 = mask2 & image_buffer[imageByte];
				#ifdef DEBUG
					std::cout << "[BEFORE SHIFT]:" << std::endl;
					// cout << "bit1: " << (int) bit1 << endl;
					// cout << "bit2: " << (int) bit2 << endl;
					std::cout << "Bit1: " << ((bit1) ? 1 : 0) << std::endl;
					std::cout << "Bit2: " << ((bit2) ? 1 : 0) << std::endl;
				#endif
				// shift them to appropriate bit positions in the buffer
				bit1 <<= (cbit);
				bit2 <<= (cbit);
				// store the bits inside the buffer
				output_buffer[curByte] |= bit1;
				output_buffer[curByte] |= bit2;

				#ifdef DEBUG
					// cout << "[AFTER SHIFT]:" << endl;
					// cout << "bit1: " << (int) bit1 << endl;
					// cout << "bit2: " << (int) bit2 << endl;
					std::cout << "Byte in imageBuffer: " << std::endl;
					showBits(&image_buffer[imageByte]);
					// cout << "[buffer]: " << endl;
					// showBits(&buffer[curByte]);
				#endif
				// go to next byte in image
				imageByte++;
			}
			// cout << "[BUFFER AFTER]: " << endl;
			// showBits(&buffer[curByte]);

		}

		#ifdef DEBUG
			std::cout << "imageByte: " << imageByte << std::endl;
		#endif
	}
}

// writes fileBuf to a file on the disk
void write_to_file(byte *output_buffer, w_uint size, std::string output_filename)
{
	std::fstream hf(output_filename, std::ios::binary | std::ios::out);

	if (hf.is_open()){
		hf.write((char *)output_buffer, size);
		hf.close();
	}
}

bool compare_signature(std::vector<byte> &signature, byte *file_buffer, int compare_size)
{
	bool result = true;
	int i = 0;

	for (auto it = signature.begin(); it != signature.end(); ++it, i++){
		if (*it != file_buffer[i]){
			result = false;
			break;
		}
	}

	return result;
}
