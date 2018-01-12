#include <iostream>

#include "headers/bmp_file.h"
#include "headers/png_file.h"

int main(void)
{
	BMPFile b("images/tiger.bmp");

	std::cout << "Testing BMP file: " << std::endl;
	std::cout << "File size: " << b.get_file_size() << std::endl;
	std::cout << "Width: " << b.get_width() << std::endl;
	std::cout << "Height: " << b.get_height() << std::endl;

	b.hide("tests/bitDriver.cpp", "");
	b.reveal("tests/out.cpp", "");

	std::cout << "Testing PNG file: " << std::endl;
	PNGFile p("images/dice.png");
	std::cout << "File size: " << p.get_file_size() << std::endl;
	std::cout << "Width: " << p.get_width() << std::endl;
	std::cout << "Height: " << p.get_height() << std::endl;

	p.hide("tests/bitDriver.cpp", "");

	return 0;
}
