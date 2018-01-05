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
		// constructor
        File(const std::string fn);

		// Takes in another file object and hides it in the current file
        virtual void hide(File &f) = 0;

        // returns the name of the file
        std::string get_file_name() const;

        // returns the size of the file
        w_uint get_file_size() const;

	private:
        std::string file_name_; // name of file
        w_uint size_; // size of file
		Byte *buffer; // file buffer

		// helper functions
        void set_file_size();
		void set_file_buffer();
};

#endif
