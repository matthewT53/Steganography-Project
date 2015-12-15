/*
	Name: Matthew Ta
	Date: 11/12/2015
	Description: Functions used to interact with files
*/

#ifndef FILE_U_H
#define FILE_U_H

// # file formats are supported
#define NUM_FORMATS_HIDE 3

// indices into the format array of ptrs to functions
#define BMP_FORMAT 0
#define JPEG_FORMAT 1
#define PNG_FORMAT 2
#define TEXT_FORMAT 4

int detFileFormat(const char *f); // determines the format of a file
unsigned int detFileSize(const char *f); // determines the size of a file

#endif
