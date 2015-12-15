/*
	Name: Matthew Ta
	Date: 7/12/2015
	Description: Interface for steganography functions
*/

#ifndef STEG_H
#define STEG_H

// common offsets in the steg image file
#define PASSWORD_OFFSET 54
#define FILE_SIZE_OFFSET 54 + 256
#define PIXEL_OFFSET 16 + 54 + 256

class Steg
{
	public:
		// constructor
		Steg(char *originalFileName = NULL, char *fileToHideName = NULL, char *stegName = NULL, char *pwd = NULL);
		
		// set and get filename
		void setOrigFileName(char *f = NULL);
		char *getOrigFileName();

		void setHideFileName(char *hf = NULL);
		char *getHideFileName(); 

		// name of file that is constructed on the disk
		void setStegFileName(char *stegName);
		char *getStegFileName(); 

		// set and get for password
		void setPassword(char *pwd = NULL);
		char *getPassword(); 	

		// hiding functions
		void beginHide();	

	private:
		char *originalFile; // name of the original file we are trying to open
		char *fileToHide; // name of fiel to hide
		char *stegFileName; // name of steg file that is created
		char *password; // stores the plain text password (will be hashed)

		// ultility functions
		void hideInBmp(); // the original image is in bmp format
		void hideInJpeg(); // the image is in jpeg format
		void hideInPng(); // the image is in png format
		
		void produceStegFile(char *stegBuffer, unsigned int bufsize); // produces a file from the steg process
};
#endif
