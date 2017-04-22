/*
	Name: Matthew Ta
	Date: 28/12/2015
	Description: Driver to test jpeg libraries
*/

#include <iostream>
#include <fstream>

#include <string.h>

#include "headers/loadjpg.h"
#include "headers/savejpg.h"
#include "headers/fileUtil.h"
#include "headers/bits.h"
#include "headers/format.h"

void storeInImage(unsigned char *bmpImageBuffer, unsigned char *dataToStore, unsigned int size);
void extractBits(unsigned char *imageBuffer, unsigned char *buffer, unsigned int numBytes); // note: buffer needs to be allocated before passing it into this function

using namespace std;

int main(void)
{
	fstream myJpg("images/plant4.jpg", ios::binary | ios::in);
	unsigned int bufSize = detFileSize("images/plant4.jpg");
	char *jpgBuf = new char [bufSize];
	unsigned char *rgbP = NULL;
	unsigned int height = 0, width = 0;

	// test data
	char *test = "hello friends I am encoded";
	unsigned char extracted[27] = {0};
	

	cout << "bufSize = " << bufSize << endl;
	if (myJpg.is_open()){
		myJpg.read(jpgBuf, bufSize);
		DecodeJpgFileData((unsigned char *) jpgBuf, bufSize, &rgbP, &width, &height);
		WriteBMP24("plant.bmp", width, height, rgbP);
		cout << "Height: " << height << endl;
		cout << "Width: " << width << endl;
		myJpg.close();

		// storeInImage(rgbP, (unsigned char *) test, strlen(test));
		// extractBits(rgbP, extracted, strlen(test));
		cout << "Extracted bits: " << extracted << endl;
		RGBToJpeg(rgbP, (width * height * 3), "new.jpg", width, height);
		cout << rgbP << endl;
		delete rgbP;
	}

	SaveJpgFile("images/tiger.bmp", "new.jpg");

	delete jpgBuf;
	
	return 0;
}

// stores size bytes from dataToStore inside bmpImageBuffer
void storeInImage(unsigned char *bmpImageBuffer, unsigned char *dataToStore, unsigned int size)
{
	unsigned int curByteBmp = 0, curBitBmp = 0;
	unsigned int curByteHide = 0, curBitHide = 0;
	Word mask = 0, bit = 0;
	cout << "Size embed: " << size << endl;
	if (bmpImageBuffer != NULL && dataToStore != NULL){
		for (curByteHide = 0; curByteHide < size; curByteHide++){ // loop through the content in the dataToStore
			// curBitBmp = 0; this produces a bug - if curBitBmp = 2 when inner loop finishes, it is reset to 0 which doesn't increment the next byte in the bmp image
			for (curBitHide = 0; curBitHide < NUM_BITS_WORD; curBitHide++){ // loop through the individual bits of each byte in the text document
				mask = 1;
				mask <<= curBitHide;
				bit = dataToStore[curByteHide] & mask; // extract a bit from a byte of the text document

				if (curBitBmp > 1){ // only hide the text bits in the 2 LSB's (least significant bits)
					curBitBmp = 0;
					curByteBmp++; // go to the next byte in the bmp file
				}

				if (bit){ // turn on a bit in a byte of the BMP
					setBit((Word *) &bmpImageBuffer[curByteBmp], curBitBmp);
				}

				else{ // turn off a bit in a byte of the BMP
					unsetBit((Word *) &bmpImageBuffer[curByteBmp], curBitBmp);
				}
			
				curBitBmp++;
			} // end of inner for loop
		} // end of outer for loop
	}
}

void extractBits(unsigned char *imageBuffer, unsigned char *buffer, unsigned int numBytes) // note: buffer needs to be allocated before passing it into this function
{
	unsigned int curByte = 0, cbit = 0, imageByte = 0;
	Word mask1 = 1, mask2 = 1;	
	Word bit1 = 0, bit2 = 0;

	if (imageBuffer != NULL && buffer != NULL){
		for (curByte = 0; curByte < numBytes; curByte++){ // loop though buffer
			// showBits(&buffer[curByte]);
			for (cbit = 0; cbit < NUM_BITS_WORD; cbit += 2){ // extract two bits at a time
				mask1 = 1;
				mask2 = 1;
				// extract the two least sig bits from each byte in the image
				mask1 <<= 0;
				mask2 <<= 1;
			
				bit1 = mask1 & imageBuffer[imageByte];
				bit2 = mask2 & imageBuffer[imageByte];
				#ifdef DEBUG
					cout << "[BEFORE SHIFT]:" << endl;
					// cout << "bit1: " << (int) bit1 << endl;
					// cout << "bit2: " << (int) bit2 << endl;
					cout << "Bit1: " << ((bit1) ? 1 : 0) << endl;
					cout << "Bit2: " << ((bit2) ? 1 : 0) << endl;
				#endif
				// shift them to appropriate bit positions in the buffer
				bit1 <<= (cbit);
				bit2 <<= (cbit);
				// store the bits inside the buffer
				buffer[curByte] |= bit1;
				buffer[curByte] |= bit2;

				#ifdef DEBUG
					// cout << "[AFTER SHIFT]:" << endl;
					// cout << "bit1: " << (int) bit1 << endl;
					// cout << "bit2: " << (int) bit2 << endl;
					cout << "Byte in imageBuffer: " << endl;
					showBits(&imageBuffer[imageByte]);
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
			cout << "imageByte: " << imageByte << endl;
		#endif
	}
}

