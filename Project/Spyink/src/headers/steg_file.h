/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: Interface for storing and processing files

	Used for reading files only.
	THis file class object doesn't allow files to be created.
*/

#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <memory>

typedef unsigned int w_uint;
typedef char Byte;

class StegFile
{
	public:
		// constructor
        StegFile(const std::string filename);

		// destructor
		~StegFile();

		// Takes in another file object and hides it in the current file
        virtual void hide(const std::string &input_filename, const std::string &password) const = 0;

		// Reveals a file that was hidden
		virtual void reveal(const std::string &output_filename, const std::string &password) const = 0;

        // returns the name of the file
        std::string get_file_name() const;

        // returns the size of the file
        w_uint get_file_size() const;

		// returns whether the file is opened
		bool is_open() const;

		// returns the file buffer
		Byte *get_buffer() const;

	protected:
		Byte *buffer_; 			  // file buffer

	private:
        std::string file_name_;   // name of file
        w_uint size_; 			  // size of file and buffer

		// helper functions
        void set_file_size();
		void set_file_buffer();
};

#endif
