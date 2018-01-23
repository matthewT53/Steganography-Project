#include <iostream>
#include <string>

#include "headers/steg.h"
#include "headers/de_steg.h"

// displays usage information
void usage();

// performs the steganography action
void do_steg(const std::string &base_filename, const std::string &input_filename, const std::string &output_filename, const std::string &password, bool is_hide, bool protect);

int main(int argc, char *argv[])
{
	bool is_hide = false;
	bool protect = false;
	std::string base_filename;
	std::string input_filename;
	std::string output_filename;
	std::string password = "";

	if (argc < 6){
		usage();
	}

	else{
		// process arguments
		for (int i = 0; i < argc; i++){
			std::string arg(argv[i]);
			if (arg == "-b"){
				base_filename = std::string(argv[++i]);
			}

			else if (arg == "-h"){
				is_hide = true;
			}

			else if (arg == "-i"){
				input_filename = std::string(argv[++i]);
			}

			else if (arg == "-r"){
				is_hide = false;
			}

			else if (arg == "-o"){
				output_filename = std::string(argv[++i]);
			}

			else if (arg == "-p"){
				password = std::string(argv[++i]);
				protect = true;
			}

			else if (arg == "--help"){
				usage();
				exit(1);
			}

			else{
				if (i > 0){ // skip the program name
					std::cout << "Flag: " << arg << " not recognised." << std::endl;
					exit(1);
				}
			}
		}

		do_steg(base_filename, input_filename, output_filename, password, is_hide, protect);
	}

	return 0;
}

void usage()
{
	std::cout << "Welcome to HideMySh!t" << std::endl;
	std::cout << "Your friendly steganography tool." << std::endl;
	std::cout << "[Options]: " << std::endl;
	std::cout << "\t-b\tSpecify base file. (used to hide a file into or reveal a hiden file)" << std::endl;
	std::cout << "\t-h\tHide a file." << std::endl;
	std::cout << "\t-i\tSpecify the input file. (Only use with the -h flag)" << std::endl;
	std::cout << "\t-r\tReveal a file." << std::endl;
	std::cout << "\t-o\tSpecify an output file. (Only use with the -r flag)" << std::endl;
	std::cout << "\t-p\tPassword to encrypt the input file or decrypt the output file. (Optional)" << std::endl;
}

void do_steg(const std::string &base_filename, const std::string &input_filename, const std::string &output_filename, const std::string &password, bool is_hide, bool protect)
{
	if (is_hide){
		Hide h(base_filename, input_filename, password);
		h.begin_hide(protect);
	}

	else{
		Reveal r(base_filename, output_filename, password);
		r.begin_reveal(protect);
	}
}
