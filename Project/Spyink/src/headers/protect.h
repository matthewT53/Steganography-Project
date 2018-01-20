/*
    Coded by: Matthew Ta
    Description: This file contains functions to encrypt or decrypt a buffer using AES-256 CBC.

    The password is converted into a SHA-256 Hash which is then used as the key to encrypt/decrypt the buffer.
*/

#ifndef PROTECT_H
#define PROTECT_H

#include <string>

typedef unsigned char Byte;

/*
    Encrypts a buffer in place using AES-256.
    [In]:
        * buffer - ptr to a buffer of bytes.
        * buf_len - size of the buffer.
        * password - password used to encrypt the buffer.
    [Out]:
        * iv - initialization vector.
*/
void encrypt(Byte *buffer, int buf_len, const std::string &password, Byte *iv);

/*
    Decrypts a buffer in place using AES-256.
    [In]:
        * buffer - ptr to a buffer of bytes.
        * buf_len - size of the buffer.
        * password - password used to encrypt the buffer.
    [Out]:
        * iv - initialization vector.
*/
void decrypt(Byte *buffer, int buf_len, const std::string &password, Byte *iv);

#endif
