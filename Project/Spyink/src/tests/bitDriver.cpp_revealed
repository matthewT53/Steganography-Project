/*
	Name: Matthew Ta
	Date: 8/12/2015
	Description: Driver to test the bits interface 
*/

#include <iostream>

#include "bits.h"

using namespace std;

int main(void)
{
	char c[4] = "abc";
	int i = 0;
	for (i = 0; i < 4; i++){
		showBits((unsigned char *)(&c[i]));
	}

	char chr = 'a';

	showBits((Word *)&chr);
	setBit((Word *) (&chr), 1);
	showBits((Word *) &chr);
	unsetBit((Word *) &chr, 0);
	showBits((Word *) &chr);

	return 0;
}
