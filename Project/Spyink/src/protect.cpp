#include <iostream>

#include "headers/protect.h"
#include "headers/aes.hpp"
#include "headers/sha256.h"

void encrypt(Byte *buffer, int buf_len, const std::string &password, Byte *iv)
{
    std::cout << "Encrypting buffer." << std::endl;
}

void decrypt(Byte *buffer, int buf_len, const std::string &password, Byte *iv)
{
    std::cout << "Decrypting buffer." << std::endl;
}
