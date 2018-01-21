#include <iostream>

#include "headers/bin_file.h"

void BinFile::hide(const std::string &input_filename, const std::string &password, bool do_encrypt) const
{
    std::cout << "Unable to hide data in a binary file." << std::endl;
}

void BinFile::reveal(const std::string &input_filename, const std::string &password, bool do_decrypt) const
{
    std::cout << "Unable to reveal data from a binary file." << std::endl;
}
