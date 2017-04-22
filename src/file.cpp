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

// File helper functions
int detFileFormat(const char *f) // determines which format a file is in
{
	int format = TEXT_FORMAT; // assume the file we open is a text file
	fstream file(f, ios::binary | ios::in); // can open original or file we trying to hide
	char *sigBuffer = NULL;
	char *signatures[SUPPORTED_FORMATS]; // array of signatures
	int headerSizes[SUPPORTED_FORMATS]; // turn all these into enum types
	int formats[SUPPORTED_FORMATS];
	int i = 0;

	buildArrays(formats, headerSizes, signatures); // init all the values

	#ifdef DEBUG
		cout << "BMP SIG: " << signatures[0] << endl;
		cout << "PNG SIG: " << signatures[1] << endl;
	#endif

	cout << "FName: " << f << endl;

	if (file.is_open()){
		for (i = 0; i < SUPPORTED_FORMATS; i++){
			sigBuffer = new char [headerSizes[i]]; // create buffer to hold signature
			memset(sigBuffer, 0, headerSizes[i]); //
			file.read(sigBuffer, headerSizes[i]);
			// memcpy(&signature, sigBuffer, headerSizes[i]);
			cout << "fmat loop: " << format << endl;
			if (memcmp(sigBuffer, signatures[i], headerSizes[i]) == 0){ // compare with the bmp signature
				#ifdef DEBUG
					cout << "Matching signatures: " << formats[i] << endl;
				#endif
				format = formats[i];
				break;
			}

			file.seekg(0, ios::beg); // reset the file ptr pos back to the start of the file
			delete sigBuffer;
		}

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
