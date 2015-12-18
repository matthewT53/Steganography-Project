/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: Interface for storing and processing files
*/

#ifndef FILE_H
#define FILE_H

#include <string>
#include "format.h"

// indexes for the dim array
#define HEIGHT 0
#define WIDTH 1

#define IMAGE_DIMENSIONS 2 // number of dimensions in an image

using namespace std;

typedef unsigned int w_uint;

class File
{
	public:
		File(const string fn); // constructor
		~File(); // destructor

		// get functions for client to use
		string getFileName();
		char *getFileBuffer();

		w_uint getFileSize();
		w_uint *getImageDim(); // should only be called for images
		w_uint getFileFormat();
		
	private:
		string fname; // name of file
		w_uint size; // size of file
		w_uint dim[IMAGE_DIMENSIONS]; // height and width, only applicable to images

		char *fbuffer; // file stored in a buffer
		int format; // identifies the type of file
		
		// set functions
		void setFileName(const string fn);
		void setFileSize();
		void setFileFormat();
		void setFileSpecs();
		
		void constructFileBuffer();
};

#endif
