/*
	Name: Matthew Ta
	Date: 7/12/2015
	Description: Implementation of the functions that perform the steganoraphy
*/

#include <iostream>
#include <fstream> // library for file I/O in c++
#include <cassert>

// useful c libraries for memory manipulations
#include <string.h>

#include "headers/steg.h"
#include "headers/file.h"
#include "headers/bits.h"
#include "headers/sha_256.h"
// #include "myStrings.h" // contains nstrinstr() and nstrinstrl() -> useful for finding strs in file buffers
#include "headers/lodepng.h" // interface for encoding/decoding png images

#define BITS_UNSIGNED_INT 32

// boolean constants
#define TRUE 1
#define FALSE 0

// #define DEBUG

// #define DEBUG // debugging constant

/*
	Logs:
	* Still need to check for weird and wonderful errors
	* apply steganography to other file formats
	* test on machines with different byte ordering
	* no need to determine the format of the file to hide
*/

using namespace std;

Hide::Hide(char *originalFileName, char *fileToHideName, char *stegName, char *pwd) // constructor function
{
	setOrigFileName(originalFileName);
	setHideFileName(fileToHideName);
	setStegFileName(stegName);
	setPassword(pwd);
}

void Hide::beginHide() // calls one of the hiding processes
{
	int origFileFormat = detFileFormat(originalFile);
	if (origFileFormat == BMP_FORMAT){
		hideInBmp();
	}

	else if (origFileFormat == PNG_FORMAT){
		hideInPng();
	}

	else{
		cout << "Unsupported file format to hide in." << endl;
	}
}

void Hide::hideInBmp() // hide file in a BMP image
{
	// make calls to the bmp class to store the file inside the bmp image
	File bmpFile(getOrigFileName());
	unsigned int bmpSize = bmpFile.getFileSize();
	// int fileHideFormat = detFileFormat(fileToHide);
	char *bmpBuffer = bmpFile.getFileBuffer(); // should we be able to modify the bmp object?
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
	strcpy((char *) hash, (char *) sha256->buffer);
	hash[SHA_256_BLOCKSIZE] = 0;

	#ifdef DEBUG
		cout << "Hash: " << hash << endl;
	#endif

	File textDoc(getHideFileName()); // create the text document object (text document represents anything really)
	char *textBuffer = textDoc.getFileBuffer(); // get the buffer containing the contents of the text file
	char size[5];
	unsigned int s = textDoc.getFileSize();
	// int enoughSpace = FALSE; // need to determine if we can fit the file

	if (textBuffer != NULL){ // check if there is a valid file buffer to write
		#ifdef DEBUG
			cout << "Text bytes: " << textDoc.getFileSize() << endl;
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

		storeInImage((Word *) (stegImageBmp + BMP_PASSWORD_OFFSET), (Word *) hash, SHA_256_BLOCKSIZE); // store the password in the bmp
		storeInImage((Word *) (stegImageBmp + BMP_FILE_SIZE_OFFSET), (Word *) size, 4); // store the size of the text file in the bmp
		storeInImage((Word *) (stegImageBmp + BMP_PIXEL_OFFSET), (Word *) textBuffer, textDoc.getFileSize()); // store the contents of the file to hide

		#ifdef DEBUG
			cout << "BMP size: " << bmpFile.getFileSize() << endl;
		#endif

		produceStegFile(bmpBuffer, bmpSize);	// create the file on the disk
	}

	delete sha256;
}

void Hide::hideInPng()
{
	// stuff for image decoding
	unsigned char *image = NULL;
	char *f = getOrigFileName();
	unsigned int height = 0, width = 0;
	unsigned int error = 0;
	int imageSize = detFileSize(f);

	// hashing stuff
	unsigned char *password = (unsigned char *) getPassword();
	unsigned char *hash = NULL;

	// file we want to hide
	File fHide(getHideFileName());
	unsigned int fileToHideSize = fHide.getFileSize();
	unsigned char *fBuf = (unsigned char *) fHide.getFileBuffer();
	char size[5];

	#ifdef DEBUG
		cout << "Image size: " << imageSize << endl;
		cout << "File to hide size: " << fileToHideSize << endl;
	#endif

	// determine if we are able to hide the data
	if (ableToStore(imageSize, (int) fileToHideSize)){
		hash = hashPassword(password);
		#ifdef DEBUG
			cout << "Hash: " << hash << endl;
		#endif

		// place the bytes of s into size
		memset(size, 0, sizeof(size));
		memcpy(size, &fileToHideSize, 4);

		error = lodepng_decode32_file(&image, &width, &height, f);
		if (error) { cout << "Error code: " << error << " means: " << lodepng_error_text(error) << endl; } // output the error

		// define offset constants
		storeInImage(image, hash, SHA_256_BLOCKSIZE); // store the hash password
		storeInImage(image + PNG_SIZE_OFFSET, (unsigned char *) size, sizeof(unsigned int)); // store the size of the file we are hiding
		// cout << "fbuf: " << fBuf << endl;
		storeInImage(image + PNG_DATA_OFFSET, fBuf, fileToHideSize); // store the file we want to hide

		error = lodepng_encode32_file(getStegFileName(), image, width, height);
		if (error) { cout << "Error code: " << error << " means: " << lodepng_error_text(error) << endl; } // output the error
		delete hash;
	}

	else{
		cout << "Unable to fit file." << endl;
	}

	delete image;
}

// generate the file formed from a steg process
void Hide::produceStegFile(char *stegBuffer, unsigned int bufsize)
{
	fstream steg(getStegFileName(), ios::binary | ios::out);
	if (steg.is_open()){
		steg.write(stegBuffer, bufsize);
		steg.close();
	}
}

void Hide::hideInJpeg() // hide file in a JPEG image
{
	cout << "Hiding in jpeg" << endl;
}

// get and set functions
void Hide::setOrigFileName(char *f)
{
	originalFile = f;
}

void Hide::setHideFileName(char *hf)
{
	fileToHide = hf;
}

void Hide::setStegFileName(char *stegName)
{
	stegFileName = stegName;
}

void Hide::setPassword(char *pwd)
{
	password = pwd;
}

char *Hide::getOrigFileName()
{
	return originalFile;
}

char *Hide::getHideFileName()
{
	return fileToHide;
}

char *Hide::getStegFileName()
{
	return stegFileName;
}

char *Hide::getPassword()
{
	return password;
}

int ableToStore(int imageSize, int fileToHideSize) // units: bytes
{
	int numBits = imageSize * 2; // # num bits that the image can hold
	int ret = FALSE;

	if ((fileToHideSize * 8) < numBits){
		ret = TRUE;
	}
	return ret;
}

// stores size bytes from dataToStore inside bmpImageBuffer
void storeInImage(unsigned char *bmpImageBuffer, unsigned char *dataToStore, unsigned int size)
{
	unsigned int curByteBmp = 0, curBitBmp = 0;
	unsigned int curByteHide = 0, curBitHide = 0;
	Word mask = 0, bit = 0;
	cout << "Size embed: " << size << endl;
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
