/*
	Name: Matthew Ta
	Date: 9/12/2015
	Description: Driver to test the text document class
*/

#include <iostream>

#include "text.h"
#include "bitmap.h"

using namespace std;

int main(void)
{
	TextDocument mydoc("test.txt");
	cout << "File name: " << mydoc.getTextFileName() << endl;
	cout << "File size: " << mydoc.getTextFileSize() << endl;
	cout << "Buffer: " << mydoc.getBuffer() << endl;
	
	TextDocument mydoc2("asfa.txt");
	cout << "File name: " << mydoc2.getTextFileName() << endl;
	cout << "File size: " << mydoc2.getTextFileSize() << endl;
	cout << "Buffer: " << mydoc2.getBuffer() << endl;
	return 0;
}
