/*
	Name: Matthew Ta
	Date: 8/12/2015
	Description: Interface for manipulating raw bits in char data types
*/

#ifndef BITS_H
#define BITS_H

// bits constants
#define NUM_BITS_WORD 8 // 8 bits in a char
#define LARGEST_POS_VALUE_CHAR 128

typedef unsigned char Word;

// for a char
void setBit(Word *w, int bitPos); // turns a specific bit on
void unsetBit(Word *w, int bitPos); // turns off a bit
void showBits(Word *w); // prints the bits

#endif
