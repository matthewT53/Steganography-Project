/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: Interface for storing and processing files
*/

#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

typedef unsigned int w_uint;
typedef char Byte;

class File
{
	public:
        File(const std::string fn); // constructor
		~File(); // destructor

        // returns the name of the file
        std::string get_file_name();

        // Takes in another file object and hides it in the current file
        virtual void hide(File &f) = 0;

        // returns the size of the file
        w_uint get_file_size();

        // returns a 1x2 array containg width and height respectively
        std::vector<w_uint> get_image_dim(); // should only be called for images

        // returns the file format of this file.
        w_uint get_file_format();

	private:
        std::string file_name_; // name of file
        w_uint size_; // size of file
        std::vector<w_uint> dim_;

        w_uint format; // identifies the type of file

		// helper functions
        void set_file_size();
        void set_file_format();
        void set_file_specs();

        void construct_file_buffer();
};

#endif
