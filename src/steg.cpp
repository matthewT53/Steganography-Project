/*
	Name: Matthew Ta
	Date: 7/12/2015
	Description: Implementation of the functions that perform the steganoraphy
*/

#include <iostream>
#include <fstream> // library for file I/O in c++

// useful c libraries for memory manipulations
#include <string.h>

#include "steg.h"
#include "bitmap.h"
#include "text.h"
#include "bits.h"
#include "fileUtil.h"
#include "sha_256.h"

#define BITS_UNSIGNED_INT 32

// #define DEBUG // debugging constant

/*
	Logs: 
	* Still need to check for weird and wonderful errors 
	* apply steganography to other file formats
	* test on machines with different byte ordering
	* no need to determine the format of the file to hide
	* text document is just a generic buffer, can contain any file format
*/

using namespace std;

// helper functions for the steg process
void storeInBmp(unsigned char *bmpImageBuffer, unsigned char *dataToStore, unsigned int size); // adds bits into a a bmp image file

Steg::Steg(char *originalFileName, char *fileToHideName, char *stegName, char *pwd) // constructor function
{
	setOrigFileName(originalFileName);
	setHideFileName(fileToHideName);
	setStegFileName(stegName);
	setPassword(pwd);
}

void Steg::beginHide() // calls one of the hiding processes
{
	int origFileFormat = detFileFormat(originalFile);
	if (origFileFormat == BMP_FORMAT){
		hideInBmp();
	}

	else{
		cout << "Unsupported file format to hide in." << endl;
	}
}

void Steg::hideInBmp() // hide file in a BMP image
{
	// make calls to the bmp class to store the file inside the bmp image
	Bitmap bmpFile(getOrigFileName());
	unsigned int bmpSize = bmpFile.getFileSize();
	// int fileHideFormat = detFileFormat(fileToHide);
	char *bmpBuffer = bmpFile.getImageBuffer(); // should we be able to modify the bmp object?
	char *stegImageBmp = bmpBuffer;

	// password hashing stuff	
	unsigned char hash[SHA_256_BLOCKSIZE];
	unsigned char *userPassword = (Word *) getPassword();	
	memset(hash, 0, SHA_256_BLOCKSIZE);
	sha256_context *sha256 = new sha256_context[1];
	sha256_start(sha256);
	sha256_update(sha256, userPassword , strlen( (char *) userPassword));
	sha256_finish(sha256, hash);
	sha256_tohex(sha256, hash);
	strcpy((char *)hash, (char *)sha256->buffer);
	hash[SHA_256_BLOCKSIZE] = 0;

	#ifdef DEBUG
		cout << "Hash: " << hash << endl;
	#endif
	
	TextDocument textDoc(getHideFileName()); // create the text document object (text document represents anything really)
	char *textBuffer = textDoc.getBuffer(); // get the buffer containing the contents of the text file
	char size[5];
	unsigned int s = textDoc.getTextFileSize();
	int enoughSpace = FALSE; // need to determine if we can fit the file

	if (textBuffer != NULL){ // check if there is a valid file buffer to write
		#ifdef DEBUG
			cout << "Text bytes: " << textDoc.getTextFileSize() << endl;
		#endif

		memset(size, 0,5);
		memcpy(size, &s, 5);

		#ifdef DEBUG
			cout << "Showing size: " << endl;
			int i = 0;
			for (i = 0; i < 4; i++){
				showBits((Word *)&size[i]);
			}
		#endif
	
		storeInBmp((Word *) (stegImageBmp + PASSWORD_OFFSET), (Word *) hash, SHA_256_BLOCKSIZE); // store the password in the bmp
		storeInBmp((Word *) (stegImageBmp + FILE_SIZE_OFFSET), (Word *) size, 4); // store the size of the text file in the bmp
		storeInBmp((Word *) (stegImageBmp + PIXEL_OFFSET), (Word *) textBuffer, textDoc.getTextFileSize()); // store the contents of the file to hide

		#ifdef DEBUG
			cout << "BMP size: " << bmpFile.getFileSize() << endl;
		#endif
	
		produceStegFile(bmpBuffer, bmpSize);	// create the file on the disk		
	}
	
	delete sha256;
}

// there is a bug in this function that doesn't store the bits correctly
void storeInBmp(unsigned char *bmpImageBuffer, unsigned char *dataToStore, unsigned int size)
{
	unsigned int curByteBmp = 0, curBitBmp = 0;
	unsigned int curByteHide = 0, curBitHide = 0;
	Word mask = 0, bit = 0;

	if (bmpImageBuffer != NULL && dataToStore != NULL){
		for (curByteHide = 0; curByteHide < size; curByteHide++){ // loop through the text document
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

// generate the file formed from a steg process
void Steg::produceStegFile(char *stegBuffer, unsigned int bufsize)
{
	fstream steg(getStegFileName(), ios::binary | ios::out);
	if (steg.is_open()){
		steg.write(stegBuffer, bufsize);
		steg.close();
	}
}

void Steg::hideInJpeg() // hide file in a JPEG image
{
	cout << "Hiding in jpeg" << endl;
}

void Steg::hideInPng() // hide file in a PNG image
{
	cout << "Hiding in png." << endl;
}

// get and set functions
void Steg::setOrigFileName(char *f)
{
	originalFile = f;
}

void Steg::setHideFileName(char *hf)
{
	fileToHide = hf;
}

void Steg::setStegFileName(char *stegName)
{
	stegFileName = stegName;
}

void Steg::setPassword(char *pwd)
{
	password = pwd;
}

char *Steg::getOrigFileName()
{
	return originalFile;
}

char *Steg::getHideFileName()
{
	return fileToHide;
}

char *Steg::getStegFileName()
{
	return stegFileName;
}

char *Steg::getPassword()
{
	return password;
}

