/*
    Author: Matthew Ta
    Date: 6/1/2018
    Description: Genric file to use.
*/

#ifndef BIN_FILE_H
#define BIN_FILE_H

#include <string>

#include "steg_file.h"

class BinFile : public StegFile
{
    public:
        // constructor
        BinFile(const std::string &filename) : StegFile(filename) {}

        // Can't hide inside binary file
        virtual void hide(const std::string &input_filename, const std::string &password) const;

        // Can't reveal from a binary file
        virtual void reveal(const std::string &output_filename, const std::string &password) const;
};

#endif
