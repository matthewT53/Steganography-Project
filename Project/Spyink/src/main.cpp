#include <iostream>

#include "headers/bmp.h"

int main(void)
{
	BMPFile b("images/tiger.bmp");

	std::cout << "File size: " << b.get_file_size() << std::endl;
	
	return 0;
}
