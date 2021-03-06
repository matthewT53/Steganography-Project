/*
	Name: Matthew Ta
	Date: 17/12/2015
	Description: Constants for different file formats
*/

#ifndef FORMAT_H
#define FORMAT_H

#define SUPPORTED_FORMATS 2

// some file formats
#define TEXT_FORMAT 0
#define BMP_FORMAT 1
#define PNG_FORMAT 2

// bitmap image constants (only the important stuff) 
#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL 24
#define BMP_HEADER_SIZE 54 // 54 bytes

// sizes in bytes
// #define BMP_SIGNATURE 0x4D42 // known bmp signature
#define BMP_SIGNATURE {0x42, 0x4D, 0};
#define BMP_SIGNATURE_SIZE 2
#define IMAGE_SIZE 4 
#define PIXELS_WIDTH 4
#define PIXELS_HEIGHT 4

// offsets
#define SIG_OFFSET 0
#define IMG_SIZE_OFFSET 2
#define PIXELS_WIDTH_OFFSET 18
#define PIXELS_HEIGHT_OFFSET 22

// common offsets in the steg image file
#define BMP_PASSWORD_OFFSET 54
#define BMP_FILE_SIZE_OFFSET 54 + 256
#define BMP_PIXEL_OFFSET 16 + 54 + 256

// PNG image constants
// #define PNG_SIGNATURE 0x89504E470D0A1A0A
// #define PNG_SIGNATURE 0x0A1A0A0D474E5089 // reverse byte order
#define PNG_SIGNATURE {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0};
#define PNG_SIGNATURE_SIZE 8
#define PNG_HEADER_SIZE PNG_SIGNATURE_SIZE

#define PNG_WIDTH_OFFSET 16
#define PNG_HEIGHT_OFFSET 20

#define PNG_HEIGHT_SIZE 4
#define PNG_WIDTH_SIZE 4

#define PNG_IMAGE_START "IDAT" // symbol in png image marking the beginning of the image data 
#define PNG_IMAGE_END "IEND" // symbol of end of png image data
#define PNG_IMAGE_DATA_OFFSET 4 // offset from chunk header

// offsets in a png image containing hidden data
#define PNG_SIZE_OFFSET 256
#define PNG_DATA_OFFSET 256 + 16

#define MAX_SIGNATURE_SIZE (PNG_SIGNATURE_SIZE + 1)

/*
	This function takes in three empty arrays and initialises them with values from
	all the image formats that are supported

	Note: In case it wasn't obvious, the arrays have to be created outside of this function
		  This function does not deal with alloc/dealloc of arrays
*/

void buildArrays(int *formats, int *sSizes, char *signatures[]); 

#endif 
