/*
	Name: Matthew Ta
	Terminal version of this program
	Usage:

	To hide an image:
	./steg -h <image file to use> <file to hide> <output file name> -p <password>

	To reveal an image:
	./steg -r <image file> <output file> -p <password>
*/

/*
	Useful links:
	* http://www.fastgraph.com/help/bmp_header_format.html
	* http://www.cplusplus.com/doc/tutorial/files/
	* http://ijact.org/volume3issue4/IJ0340004.pdf
*/

#include <iostream>

#include <string.h>

#include "headers/steg.h"
#include "headers/deSteg.h"
#include "headers/bits.h"

enum processes{
	HIDE,
	REVEAL,
	ERROR
};

#define MAX_LEN 250

using namespace std;

// displays the usage information for this program
void usage();

// determines whether the user wants to hide or reveal
int checkProcess(int max, char **arguments, char *imageFile, char *inputFile, char *outputFile, char *password);

int main(int argc, char **argv)
{
	char imageFile[MAX_LEN] = {0}, inputFile[MAX_LEN] = {0}, outputFile[MAX_LEN] = {0}, password[MAX_LEN] = {0};

	// check that the user provided the correct number of arguments
	if (argc == 7 || argc == 6){
		int process = checkProcess(argc, argv, imageFile, inputFile, outputFile, password);

		if (process == HIDE){
			Hide hideFile(imageFile, inputFile, outputFile, password);
			hideFile.beginHide();
		}

		else if (process == REVEAL){
			Reveal hidden(imageFile, outputFile, password);
			hidden.reveal();
		}

		else{
			cout << "Error determing which process to perform" << endl;
		}
	}

	else{
		usage();
	}

	return 0;
}

int checkProcess(int max, char **arguments, char *imageFile, char *inputFile, char *outputFile, char *password)
{
	int process = ERROR;
	int i = 0;

	while (i < max){
		if (strcmp(arguments[i], "-h") == 0){
			process = HIDE;
			memcpy(imageFile, arguments[i + 1], MAX_LEN);
			memcpy(inputFile, arguments[i + 2], MAX_LEN);
			memcpy(outputFile, arguments[i + 3], MAX_LEN);
		}

		else if (strcmp(arguments[i], "-r") == 0){
			process = REVEAL;
			memcpy(imageFile, arguments[i + 1], MAX_LEN);
			memcpy(outputFile, arguments[i + 2], MAX_LEN);
		}

		else if (strcmp(arguments[i], "-p") == 0){
			memcpy(password, arguments[i + 1], MAX_LEN);
		}

		i++;
	}

	return process;
}

void usage()
{
	cout << "Hide a file: " << endl;
	cout << "./steg -h <image file to use> <file to hide> <output file name> -p <password>" << endl;
	cout << "Reveal a file " << endl;
	cout << "./steg -r <image file> <output file> -p <password>" << endl;
}

/*
void test1()
{
	cout << "Testing the bitmap class: " << endl;
	Bitmap bmp("tiger.bmp");
	cout << "File size: " << bmp.getFileSize() << endl;
	cout << "Number of pixels: " << bmp.getNumPixels() << endl;
	cout << "File name: " << bmp.getFileName() << endl;

	cout << "Testing the steg class: " << endl;
	char *of = "tiger.bmp";
	char *hf = "test.txt";
	char *p = "theBoss45";
	char *steg = "stegimage.bmp";
	Steg mySteg(of, hf, steg, p); // does not crash even if no arguments are given
	mySteg.beginHide();

	cout << "Original file: " << mySteg.getOrigFileName() << endl;
	cout << "File to hide: " << mySteg.getHideFileName() << endl;
	cout << "Password: " << mySteg.getPassword() << endl;

	cout << "Testing some type casting stuff." << endl;
	int size = 19;
	unsigned char *str = (unsigned char *) &size;
	showBits(str);
	hf = "hidden.txt";
	Reveal r(hf, steg, p);
	cout << "Info about the steg image: " << endl;
	cout << "Size of steg image: " << r.getSizeOfStegImage() << endl;
	cout << "Size of hidden file: " << r.getSizeOfHiddenFile() << endl;
	r.reveal();

}
*/
