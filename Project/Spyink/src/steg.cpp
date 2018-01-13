#include <iostream>
#include <string>
#include <vector>

#include "headers/steg.h"
#include "headers/bmp_file.h"
#include "headers/png_file.h"
#include "headers/bin_file.h"

// determines the type of a file based on known signatures
bool compare_signature(std::vector<Byte> &signature, Byte *file_buffer, int compare_size);

Hide::Hide(const std::string &base_filename, const std::string &input_filename, const std::string &password)
: input_filename_{input_filename}, password_{password}
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

Hide::~Hide()
{
	delete base_file_;
}

void Hide::begin_hide() const
{
	std::cout << input_filename_ << std::endl;
	std::cout << password_ << std::endl;
	base_file_->hide(input_filename_, password_);
}

bool compare_signature(std::vector<Byte> &signature, Byte *file_buffer, int compare_size)
{
	bool result = true;
	int i = 0;

	for (auto it = signature.begin(); it != signature.end(); ++it, i++){
		if (*it != file_buffer[i]){
			result = false;
			break;
		}
	}

	return result;
}
