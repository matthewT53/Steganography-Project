# Steganography-Project
This software is able to hide any file in a variety of image and video formats.

# Supported formats:
* Text
* BMP
* PNG
* JPEG (work in progress)

# Installing:
Execute the Makefile to compile all the source files.

# Usage:
* To hide a file:  
`./steg -h <image file> <file to hide> <output file> -p <password>`
* To reveal a hidden file:  
`./steg -r <image file> <output file> -p <password>`

# Future work:
* Add more file types that the user can use to hide stuff inside.
* Allow the user to encrypt any files they want to hide.
* Create a small and simple GUI for this program.
