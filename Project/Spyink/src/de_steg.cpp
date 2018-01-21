#include <iostream>
#include <string>

#include "headers/de_steg.h"
#include "headers/bmp_file.h"
#include "headers/png_file.h"
#include "headers/bin_file.h"
#include "headers/steg_helper.h"

Reveal::Reveal(const std::string &base_filename, const std::string &output_filename, const std::string &password)
: output_filename_{output_filename}, password_{password}
{
    BinFile *base_bin_ = new BinFile{base_filename};

	// check the file type of the base file
	Byte *base_buffer = base_bin_->get_buffer();

	if (compare_signature(BMPFile::signature_, base_buffer, BMPFile::signature_.size())){
		std::cout << "Detected a BMP file." << std::endl;
		base_file_ = new BMPFile(base_filename);
	}

	else if (compare_signature(PNGFile::signature_, base_buffer, PNGFile::signature_.size())){
		std::cout << "Detected a PNG file." << std::endl;
		base_file_ = new PNGFile(base_filename);
		std::cout << "Finished casting." << std::endl;
	}

	delete base_bin_;
}

Reveal::~Reveal()
{
    delete base_file_;
}

void Reveal::begin_reveal(bool do_decrypt) const
{
    base_file_->reveal(output_filename_, password_, do_decrypt);
}
