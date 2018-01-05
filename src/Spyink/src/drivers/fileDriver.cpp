/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: Driver to test the file class
*/

#include <iostream>
#include <string>

#include "file.h"

void info(File &f);

int main(void)
{
	File myFile("tiger.bmp");
	info(myFile);

	File fpng("bullet_red.png");
	info(fpng);

	File text("test");
	info(text);
}

void info(File &f)
{
	cout << "File Name: " << f.getFileName() << endl;
	cout << "File Size: " << f.getFileSize() << endl;
	w_uint *d = f.getImageDim();
	cout << "Image Height: " << d[HEIGHT] << endl;
	cout << "Image Width: " << d[WIDTH] << endl;
	cout << "File format: " << f.getFileFormat() << endl;
	cout << "Buffer: " << f.getFileBuffer() << endl;
}
