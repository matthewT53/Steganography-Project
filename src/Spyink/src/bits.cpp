/*
	Name: Matthew Ta
	Date: 8/12/2015
	Description: Implementation of the interface for manipulating raw bits
*/

#include <iostream>

#include "headers/bits.h"

/*
	Notes:
	* bitPos should take values from 0 - 7, anything else will just wrap around
	* bitPos = 0 will represent the value of 1 and bitPos = 7 will shift to the value 128 
*/

using namespace std;

/* ================= for unsigned char ============ */

// turn a bit on
void setBit(Word *w, int bitPos)
{
	Word mask = 1;
	mask <<= bitPos;
	*w |= mask;
}

// turn a bit off
void unsetBit(Word *w, int bitPos)
{
	Word mask = 1;
	mask <<= bitPos;
	mask = ~mask;
	*w &= mask;
}

// show bits
void showBits(Word *w)
{
	int i = 0;
	Word mask = LARGEST_POS_VALUE_CHAR;
	Word res = 0;
    cout << "w: " << *w << endl;
    cout << "[";
	for (i = 0; i < NUM_BITS_WORD; i++){
		res = *w & mask;
        // cout << ((res) ? 1 : 0);
		// cout << "mask: " << (char) mask << endl;
		mask = mask >> 1;
	}
    cout << "]" << endl;
}

