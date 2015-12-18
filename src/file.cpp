/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: File storage and processing functions
*/

#include <iostream>
#include <fstream>
#include <string>

// standard c headers
#include "string.h"

// project headers
#include "headers/file.h"
#include "headers/format.h"
#include "headers/fileUtil.h"

using namespace std;

File::File(const string fn) // constructor function
{
	setFileName(fn);
	setFileSize();
	setFileFormat();
	constructFileBuffer();
	setFileSpecs(); // this relies on the buffer being constructed
}

File::~File() // destructor function
{
	delete fbuffer;
}

// set functions
void File::setFileName(const string fn)
{
	fname = fn;
}

void File::setFileSize()
{
	size = detFileSize(getFileName().c_str());
}

void File::setFileFormat()
{
	format = detFileFormat(getFileName().c_str());
}

void File::setFileSpecs()
{
	char *buf = getFileBuffer();
	int form = getFileFormat();

	if (buf != NULL){
		if (form == BMP_FORMAT){
			memcpy(&dim[WIDTH], buf + PIXELS_WIDTH_OFFSET, PIXELS_WIDTH);
			memcpy(&dim[HEIGHT], buf + PIXELS_HEIGHT_OFFSET, PIXELS_HEIGHT);
		}

		else if (form == PNG_FORMAT){
			cout << "Not determined yet." << endl;
		}

		else{
			cout << "Not applicable" << endl;
		
		}
	}
}

void File::constructFileBuffer() // reads contents of file into buffer
{
	fstream f(getFileName().c_str(), ios::binary | ios::in);
	w_uint fs = getFileSize();
	fbuffer = new char [fs];

	if (f.is_open()){
		f.read(fbuffer, fs);
		f.close();
	}	

	else{
		fbuffer = NULL;
	}
}

// get functions
string File::getFileName()
{
	return fname;
}

char *File::getFileBuffer()
{
	return fbuffer;
}

w_uint File::getFileSize()
{
	return size;
}

w_uint *File::getImageDim()
{
	return dim;
}

w_uint File::getFileFormat()
{
	return format;
}




