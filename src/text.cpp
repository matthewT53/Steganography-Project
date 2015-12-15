/*
	Name: Matthew Ta
	Date: 9/12/2015
	Description: Implementation of the functions that allow the client to interact with a text document
*/

#include <iostream>
#include <fstream>

#include "text.h"

using namespace std;

TextDocument::TextDocument(const char *f) // constructor function
{
	setFileName(f);
	setFileSize();
	setTextBuffer();
}

TextDocument::~TextDocument() // destructor function
{
	delete buffer;
}

void TextDocument::setFileName(const char *f) // stores the file's name
{
	fileName = (char *) f;
}

void TextDocument::setFileSize()
{	
	fstream textFile(fileName, ios::in | ios::binary | ios::ate); // set the file position to end of file
	if (textFile.is_open()){ // check if we opened the file properly
		fileSize = textFile.tellg(); // file pos is set to EOF, hence this returns the size
		textFile.close();
	}
}

void TextDocument::setTextBuffer() // read the file into a buffer
{
	fstream textFile(fileName, ios::binary | ios::in);
	buffer = new char [fileSize]; // allocate memory for the buffer
	if (textFile.is_open()){
		textFile.read(buffer, fileSize); // read the file's contents into a buffer
		textFile.close();
	}	
}

char *TextDocument::getTextFileName() // return the name of the file
{
	return fileName;
}

unsigned int TextDocument::getTextFileSize() // return the size of the text file
{
	return fileSize;
}

char *TextDocument::getBuffer() // return the buffer containing the text file
{
	return buffer;
}










