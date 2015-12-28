/*
	Name: Matthew Ta
	Date: 18/12/2015
	Description: Impl of functions that allow client to interact with format constants
*/

#include <iostream>

#include <string.h>

#include "headers/format.h"

using namespace std;

void buildArrays(int *formats, int *sSizes, char *signatures[])
{
	char bmpSig[BMP_SIGNATURE_SIZE + 1] = BMP_SIGNATURE;
	char pngSig[PNG_SIGNATURE_SIZE + 1] = PNG_SIGNATURE;
	
	// set the formats array
	formats[0] = BMP_FORMAT;
	formats[1] = PNG_FORMAT;

	// set the format sizes array
	sSizes[0] = BMP_SIGNATURE_SIZE;
	sSizes[1] = PNG_SIGNATURE_SIZE;

	// fill the signatures array
	signatures[0] = new char [BMP_SIGNATURE_SIZE + 1];
	signatures[1] = new char [PNG_SIGNATURE_SIZE + 1];

	strcpy(signatures[0], bmpSig);
	strcpy(signatures[1], pngSig);
}

