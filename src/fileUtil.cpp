/*
	Name: Matthew Ta
	Date: 11/12/2015
	Description: Implementation of functions used to interact with files
*/

#include <iostream>
#include <fstream>

#include <string.h>

#include "headers/fileUtil.h"
#include "headers/format.h"

#define DEBUG

using namespace std;

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
			if (strcmp(sigBuffer, signatures[i]) == 0){ // compare with the bmp signature
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
