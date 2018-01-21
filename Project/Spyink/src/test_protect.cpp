/*
    Coded by: Matthew Ta
    Description: This file tests the protection subroutines in protect.cpp
*/

#include <iostream>

#include "headers/protect.h"

int main(void)
{
    Byte buffer[] = "ghello world1234ghello world1234567891adfg67jn";
    // Byte iv[] = "dsafsdgsfsd dsdsf";
    std::string password = "mypassa";

    encrypt(buffer, 46, password);

    std::cout << "After encryption: " << buffer << std::endl;

    decrypt(buffer, 46, password);

    std::cout << "After decryption: " << buffer << std::endl;
    return 0;
}
