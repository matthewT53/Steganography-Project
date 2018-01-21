#ifndef PNG_FILE_H
#define PNG_FILE_H

#include <string>
#include <vector>

#include "steg_file.h"

class PNGFile : public StegFile
{
    public:
        // constructor
        PNGFile(const std::string &filename);

        // destructor
        virtual ~PNGFile();

        // hides a file in this PNG image
        virtual void hide(const std::string &input_filename, const std::string &password, bool do_encrypt) const;

        // reveals a file that was hidden
        virtual void reveal(const std::string &output_filename, const std::string &password, bool do_decrypt) const;

        // returns the height
        w_uint get_height() const;

        // returns the width
        w_uint get_width() const;

        // signjature of the png file
        static std::vector<Byte> signature_;

    private:
        w_uint height_;
        w_uint width_;

        // raw image data
        Byte *image_data_;
};

#endif
