/*
	Name: Matthew Ta
	Date: 13/1/2018
	Description: Interface for functions that can reveal files hidden in an image or other media files.
*/

#ifndef DE_STEG_H
#define DE_STEG_H

#include <string>

#include "steg_file.h"

class Reveal
{
	public:
		// constructor
		Reveal(const std::string &base_filename, const std::string &output_filename, const std::string &password);

		// destructor
		~Reveal();

		// start the revealing process
		void begin_reveal(bool do_decrypt = false) const;

	private:
		StegFile *base_file_;
		std::string output_filename_;
		std::string password_;
};
#endif
