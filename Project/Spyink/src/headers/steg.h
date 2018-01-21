/*
	Name: Matthew Ta
	Date: 13/1/2018
	Description: Interface for steganography functions
*/

#ifndef STEG_H
#define STEG_H

#include <string>

#include "steg_file.h"

class Hide
{
	public:
		/*
			Parameters:
			* base_filename - file that will be used to store other files.
			* input_filename - file to hide inside the base file.
			* output_filename - file that will contain the input file inside a base file.
			* password - password for encryption (optional)
		*/
		Hide(const std::string &base_filename, const std::string &input_filename, const std::string &password);

		// destructor
		~Hide();

		// begin the hide process
		void begin_hide(bool do_encrypt = false) const;

	private:
		StegFile *base_file_;
		std::string input_filename_;
		std::string password_;
};
#endif
