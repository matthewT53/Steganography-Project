#include <iostream>

#include "headers/bmp_file.h"
#include "headers/png_file.h"

int main(void)
{
	BMPFile b("images/tiger.bmp");

	std::cout << "File size: " << b.get_file_size() << std::endl;
	std::cout << "Width: " << b.get_width() << std::endl;
	std::cout << "Height: " << b.get_height() << std::endl;

	b.hide("tests/bitDriver.cpp", "");
	b.reveal("tests/out.cpp", "");

	

	return 0;
}
