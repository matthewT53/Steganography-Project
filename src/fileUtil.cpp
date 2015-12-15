/*
	Name: Matthew Ta
	Date: 11/12/2015
	Description: Implementation of functions used to interact with files
*/

#include <iostream>
#include <fstream>

#include <string.h>

#include "fileUtil.h"
#include "bitmap.h"

using namespace std;

int detFileFormat(const char *f) // determines which format a file is in
{
	int format = TEXT_FORMAT; // assume the file we open is a text file
	fstream file(f, ios::binary | ios::in); // can open original or file we trying to hide
	int signature = 0;
	char *sigBuffer = new char [BMP_SIGNATURE_SIZE + 1];
	
	if (file.is_open()){
		memset(sigBuffer, 0, BMP_SIGNATURE_SIZE + 1);
		file.read(sigBuffer, BMP_SIGNATURE_SIZE);
		memcpy(&signature, sigBuffer, BMP_SIGNATURE_SIZE);
	
		if (signature == BMP_SIGNATURE){ // compare with the bmp signature
			#ifdef DEBUG
				cout << "Matching bmp signatures." << endl;
			#endif
			format = BMP_FORMAT;
		}

		file.seekg(0, ios::beg); // reset the file ptr pos back to the start of the file
		file.close();
	}
	return format;
}

unsigned int detFileSize(const char *f) // determine the size of the file
{
	unsigned int fileSize = 0;
	fstream file(f, ios::binary | ios::in | ios::ate); // place file pos to end of file
	if (file.is_open()){ // check if file opened correctly
		fileSize = (int) file.tellg();
		file.close();
	}
	return fileSize;
}
