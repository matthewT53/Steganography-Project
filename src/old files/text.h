/*
	Name: Matthew Ta
	Date: 9/12/2015
	Description: Interface for interacting with a text document
*/

#ifndef TEXT_H
#define TEXT_H

class TextDocument
{
	public:
		TextDocument(const char *f); // constructor
		~TextDocument(); // destructor, free buffers
		
		// get functions
		char *getTextFileName();
		unsigned int getTextFileSize(); // 
		char *getBuffer(); // returns the text document in a buffer

	private:
		char *fileName; // name of the text file
		unsigned int fileSize; // size of the text file
		char *buffer; // holds the text document

		// set functions
		void setFileName(const char *f); // sets the file name
		void setFileSize(); // determines the file size
		void setTextBuffer(); // transfer the text files content into a buffer
};
#endif
