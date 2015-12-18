/*
	Name: Matthew Ta
	Implementation of the interface for manipulating bitmap files
*/

#include <iostream>
#include <fstream>

// useful C libraries
#include <string.h>

#include "headers/bitmap.h"

// #define DEBUG // debugging constant

using namespace std;

Bitmap::Bitmap(const char *f)
{
	fstream bmpFile(f, ios::binary | ios::in); // generic file stream, can be input or output
	char header[BMP_HEADER_SIZE];
	setFileName(f);
	memset(header, 0, BMP_HEADER_SIZE); // clear the memory of the header

	if (bmpFile.is_open()){ // check if the file has been opened properly
		bmpFile.read(header, BMP_HEADER_SIZE);
		bmpImageInfo(header);
		bmpFile.close();

		setImageBuffer(); // read the bmp image into the large buffer
	}
}

Bitmap::~Bitmap()
{
	delete imageBuffer;
}

void Bitmap::bmpImageInfo(const char *header)
{
	short int signature = 0;
	unsigned int bmpSize = 0;
	int pixWidth = 0, pixHeight = 0;
	
	// memset(signature, 0, SIGNATURE_SIZE + 1);
	memcpy(&signature, header, BMP_SIGNATURE_SIZE);
	#ifdef DEBUG
		cout << "Read sig: " << signature << endl;
		cout << "Known sig: " << BMP_SIGNATURE << endl;
	#endif
	if (signature == BMP_SIGNATURE){
		cout << "Signatures match." << endl;
	}

	memcpy(&bmpSize, (header + IMG_SIZE_OFFSET), IMAGE_SIZE);
	memcpy(&pixWidth, header + PIXELS_WIDTH_OFFSET, PIXELS_WIDTH);
	memcpy(&pixHeight, header + PIXELS_HEIGHT_OFFSET, PIXELS_HEIGHT);
	
	#ifdef DEBUG
	cout << "Image size: " << bmpSize << " bytes." << endl; 
	cout << "Width: " << pixWidth << endl;
	cout << "Height: " << pixHeight << endl;
	#endif
	
	setFileSize(bmpSize);
	setNumPixels(pixWidth * pixHeight);
}

void Bitmap::setImageBuffer()
{
	fstream bmpFile(fileName, ios::binary | ios::in);
	imageBuffer = new char [fileSize];
	memset(imageBuffer, 0, fileSize);
	
	if (bmpFile.is_open()){
		bmpFile.read(imageBuffer, fileSize); // consider typecasting to unsigned char once here
		bmpFile.close();
	}
}

/* get functions */

// returns the file name of the bitmap
char *Bitmap::getFileName()
{
	return fileName;
}

// returns the file size of the image
unsigned int Bitmap::getFileSize()
{
	return fileSize;
}

// returns the # of pixels
int Bitmap::getNumPixels()
{
	return numberOfPixels;
}

char *Bitmap::getImageBuffer()
{
	return imageBuffer;
}

/* set functions */
void Bitmap::setFileName(const char *f)
{
	fileName = (char *) f; // hacky way will change later
}

void Bitmap::setFileSize(const unsigned int size)
{
	fileSize = size;
}

void Bitmap::setNumPixels(const int numPix)
{
	numberOfPixels = numPix;
}




