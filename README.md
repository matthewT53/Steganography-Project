# Steganography-Project
This software is able to hide any binary file into the following file formats:
* BMP image
* PNG image

# Features:
* AES (ECB) encryption of the input file.

# Installing:
## Command line version
* Run the makefile under "Project/Spyink/src/".

# Usage:
* To hide a file:  
`./steg -h -b <image file> -i <input file> -p <password>`
* To reveal a hidden file:  
`./steg -r -b <images file> -o <output file> -p <password>`

# Future work:
* Implement the more secure CBC mode for AES.
* Add support for JPEG and other file types.

# Libaries used:
* lodepng - https://github.com/lvandeve/lodepng
* Tiny AES - https://github.com/kokke/tiny-AES-c
* SHA256 - https://github.com/pgarnaut/sha256
