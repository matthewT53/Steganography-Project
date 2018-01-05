/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: File storage and processing functions
*/

#include <iostream>
#include <fstream>
#include <string>

// standard c headers
#include "string.h"

// project headers
#include "headers/file.h"

File::File(const std::string file_name) // constructor function
    : file_name_{file_name}
{
	set_file_size();
}

// determines the file's size
void File::set_file_size()
{
	w_uint fileSize = 0;
	std::fstream file(file_name_, std::ios::binary | std::ios::in | std::ios::ate); // place file pos to end of file
	if (file.is_open()){ // check if file opened correctly
		fileSize = (int) file.tellg();
		file.close();
	}

	else{
        std::cout << "Error getting file size." << std::endl;
	}

	size_ = fileSize;
}

// reads the file's contents into a buffer
void File::set_file_buffer()
{
    
}

// get functions
std::string File::get_file_name() const
{
	return file_name_;
}

w_uint File::get_file_size() const
{
	return size_;
}
