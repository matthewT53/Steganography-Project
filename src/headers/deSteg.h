/*
	Name: Matthew Ta
	Date: 10/12/2015
	Description: Interface for functions that can de-steg an image formed by stegonagraphy
*/

#ifndef DESTEG_H
#define DESTEG_H

class Reveal
{
	public:
		Reveal(char *imageFile = NULL, char *outputFile = NULL, char *pass = NULL); // constructor function
		~Reveal(); // destructor function

		// reveal process
		void reveal(); // removes hidden files from a steg image

		// get functions
		char *getNameOfHiddenFile();
		char *getNameOfStegImage();
		char *getPassword();
		char *getStegImageBuffer();
		unsigned int getSizeOfHiddenFile();
		unsigned int getSizeOfStegImage();

	private:
		char *nameOfHiddenFile; // file removed from steg image
		char *nameOfStegImage; // name of the steg image

		unsigned int hiddenFileSize; // size of the file to be removed
		unsigned int stegImageSize; // size of the steg image

		char *stegImageBuffer; // buffer holding the contents of the steg image
		char *password; // password to unlock the file

		// utility functions
		void setFileSizes();

		// reveal a specific image format
		void revealBmp();
		void revealPng();

		// set functions
		void setNameOfHiddenFile(char *nhf);
		void setNameOfStegImage(char *nsi);
		void setPassword(char *p);
		void setStegImageBuffer();
};
#endif
