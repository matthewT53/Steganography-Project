#ifndef PNG_FILE_H
#define PNG_FILE_H

#include <string>

#include "steg_file.h"

class PngFile : public StegFile
{
    public:
        // constructor
        PngFile(const std::string &filename);

        // hides a file in this PNG image
        virtual void hide(const std::string &input_filename, const std::string &password) const;

        // reveals a file that was hidden
        virtual void reveal(const std::string &output_filename, const std::string &password) const;

        // returns the height
        w_uint get_height() const;

        // returns the width
        w_uint get_width() const;

    private:
        w_uint height_;
        w_uint width_;

        // raw image data
        Byte **image_data_;


};

#endif
