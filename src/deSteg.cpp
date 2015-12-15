/*
	Name: Matthew Ta
	Date: 10/12/2015
	Description: Functions that remove stegonagraphy from images
*/

#include <iostream>
#include <fstream>
#include <cassert>

#include <string.h>

#include "headers/deSteg.h"
#include "headers/bitmap.h"
#include "headers/bits.h"
#include "headers/fileUtil.h"
#include "headers/sha_256.h"

// #define DEBUG

using namespace std;

// helper functions
void extractBits(unsigned char *imageBuffer, unsigned char *buffer, unsigned int numBytes); // removes numBytes * 8 bits and stores the info in buffer
void writeToFile(char *fileBuffer, unsigned int size, char *fname); // should it take fileFormat as a parameter?

Reveal::Reveal(char *nhf, char *nsi, char *pass) // constructor 
{
	setNameOfHiddenFile(nhf);
	setNameOfStegImage(nsi);
	setPassword(pass);
	setFileSizes();
	setStegImageBuffer();
}

Reveal::~Reveal() // destructor
{
	delete stegImageBuffer;
}

void Reveal::reveal() // removes hidden files from a steg image
{
	// assume the file he user gave us has had stegonagrpahy applied to it
	int fileFormat = detFileFormat(getNameOfStegImage());
	if (fileFormat == BMP_FORMAT){
		revealBmp();
	}
		
	else{
		cout << "The file format is not currently supported." << endl;
	}
	
}

// Note: need to make code neater by removing unecessary typecasting
// Experiment with byte ordering
void Reveal::revealBmp() // reveal hidden files ina bmp image
{
	// get the password and verify it
	unsigned char *userPassword = (unsigned char *) getPassword();
	unsigned char hash[SHA_256_BLOCKSIZE + 1];
	char storedHash[SHA_256_BLOCKSIZE + 1];
	sha256_context *sha256 = new sha256_context[1];
	char *imageBuffer = getStegImageBuffer();
	char imageSize[5];
	char *fileBuf = NULL;
	unsigned int hfSize = 0;

	assert(sha256 != NULL && storedHash != NULL && userPassword != NULL);
	
	// clear storage arrays
	memset(imageSize, 0, 5);
	memset(hash, 0, SHA_256_BLOCKSIZE + 1);
	memset(storedHash, 0, SHA_256_BLOCKSIZE + 1);

	// hash the password
	sha256_start(sha256);
	sha256_update(sha256, userPassword, strlen((char *)userPassword));
	sha256_finish(sha256, hash);
	sha256_tohex(sha256, hash);

	extractBits((Word *) (imageBuffer + PASSWORD_OFFSET), (Word *) storedHash, SHA_256_BLOCKSIZE);
	strncpy((char *) hash, (char *) sha256->buffer, SHA_256_BLOCKSIZE); // the sha256->buffer is not null terminated
	#ifdef DEBUG 
		cout << "Our hash: " << hash << endl;
		cout << "Stored hash: " << storedHash << endl;
	#endif

	// check if user entered a matching password
	if (strcmp((char *) hash, storedHash) == 0){
		extractBits((Word *) (imageBuffer + FILE_SIZE_OFFSET), (Word *) imageSize, sizeof(int));
		memcpy(&hfSize, imageSize, sizeof(unsigned int));
	
		fileBuf = new char [hfSize]; // create new buffer to store the file's contents
		memset(fileBuf, 0, hfSize);
		extractBits((Word *) (imageBuffer + PIXEL_OFFSET), (Word *) fileBuf, hfSize); // extract the hidden file
		writeToFile(fileBuf, hfSize, getNameOfHiddenFile()); // write to disk
		delete fileBuf;
	}

	else{
		cout << "Password entered is incorrect." << endl;
	}

	delete sha256;
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

// writes fileBuf to a file on the disk
void writeToFile(char *fileBuf, unsigned int size, char *fname)
{
	fstream hf(fname, ios::binary | ios::out);

	if (hf.is_open()){
		hf.write(fileBuf, size);
		hf.close();
	}
}

void Reveal::setFileSizes() // calls a function to determine the size
{
	hiddenFileSize = detFileSize(nameOfHiddenFile);
	stegImageSize = detFileSize(nameOfStegImage);
}

// set functions
void Reveal::setNameOfHiddenFile(char *nhf)
{
	nameOfHiddenFile = nhf;
}

void Reveal::setNameOfStegImage(char *nsi)
{
	nameOfStegImage = nsi;
}

void Reveal::setPassword(char *pass)
{
	password = pass;
}

void Reveal::setStegImageBuffer() // read the steg image into a buffer
{
	fstream stegFile(nameOfStegImage, ios::binary | ios::in);
	stegImageBuffer = new char [stegImageSize];

	if (stegFile.is_open()){ // ensure that we opened the file correctly
		stegFile.read(stegImageBuffer, stegImageSize);
		stegFile.close();
	}
}

// get functions
char *Reveal::getNameOfHiddenFile()
{
	return nameOfHiddenFile;
}

char *Reveal::getNameOfStegImage()
{
	return nameOfStegImage;
}

char *Reveal::getPassword()
{
	return password;
}

char *Reveal::getStegImageBuffer()
{
	return stegImageBuffer;
}

unsigned int Reveal::getSizeOfHiddenFile()
{
	return hiddenFileSize;
}

unsigned int Reveal::getSizeOfStegImage()
{
	return stegImageSize;
}






