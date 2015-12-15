/*
	Name: Matthew Ta
	Driver for testing steganography processes
*/

/* 
	Useful links:
	* http://www.fastgraph.com/help/bmp_header_format.html
	* http://www.cplusplus.com/doc/tutorial/files/
	* http://ijact.org/volume3issue4/IJ0340004.pdf
*/

#include <iostream>

#include <string.h>

#include "headers/bitmap.h"
#include "headers/steg.h"
#include "headers/deSteg.h"
#include "headers/bits.h"

#define MAX_LEN 200

using namespace std;

void test1();

int main()
{
	char bmp[MAX_LEN], out[MAX_LEN], hide[MAX_LEN], password[MAX_LEN];
	
	int choice = 0;

	memset(bmp, 0, MAX_LEN);
	memset(out, 0, MAX_LEN);
	memset(hide, 0, MAX_LEN);
	memset(password, 0, MAX_LEN);

	cout << "Hide or reveal: " << endl;
	cin >> choice;

	if (choice){ // hide
		cout << "Enter BMP file: " << endl;
		cin >> bmp;
		cout << "Enter file to hide: " << endl;
		cin >> hide;
		cout << "Enter output image: " << endl;
		cin >> out;
		cout << "Enter a password: " << endl;
		cin >> password;
		
		Steg hideImage(bmp, hide, out, password);
		hideImage.beginHide();
	}

	else{
		cout << "Enter image to reveal: " << endl;
		cin >> bmp;
		cout << "Enter name of file revealed: " << endl;
		cin >> hide;
		cout << "Enter password: " << endl;
		cin >> password;
		
		Reveal r(hide, bmp, password);
		r.reveal();
	}

	return 0;
}

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
