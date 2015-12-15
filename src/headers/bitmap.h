/*
	Name: Matthew Ta
	Interface for manipulating bitmap files
*/

#ifndef BITMAP_H
#define BITMAP_H

// bitmap image constants (only the important stuff) 

#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL 24
#define BMP_HEADER_SIZE 54 // 54 bytes

// sizes in bytes
#define BMP_SIGNATURE 0x4D42 // known bmp signature
#define BMP_SIGNATURE_SIZE 2
#define IMAGE_SIZE 4 
#define PIXELS_WIDTH 4
#define PIXELS_HEIGHT 4

// offsets
#define SIG_OFFSET 0
#define IMG_SIZE_OFFSET 2
#define PIXELS_WIDTH_OFFSET 18
#define PIXELS_HEIGHT_OFFSET 22

class Bitmap
{
	public:
		// functions that allow the bitmap image to be copied and modified
		Bitmap(const char *f = NULL); // constructor - stores the image in a buffer
		~Bitmap(); // destructor for cleanup

		// set and get functions for the filename of the bitmap file
		char *getFileName(); 
		unsigned int getFileSize(); // returns file size
		int getNumPixels(); // returns # pixels in image
		char *getImageBuffer(); // returns the image buffer to client

	private:
		// private data members
		unsigned int fileSize; // size of the bitmap image
		char *fileName; // name of the file
		char *imageBuffer; // large buffer to hold image
		int numberOfPixels; // # pixels in the image

		// utility functions
		void bmpImageInfo(const char *header); // stores info about the bmp image
		void setFileName(const char *f); // set the file's name
		void setFileSize(const unsigned int size); // set the file size
		void setNumPixels(const int numPix); // sets the number of pixels in the image
		void setImageBuffer(); // stores the image inside a large buffer
};

#endif
