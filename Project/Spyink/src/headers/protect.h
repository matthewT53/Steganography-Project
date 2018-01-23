/*
    Coded by: Matthew Ta
    Description: This file contains functions to encrypt or decrypt a buffer using AES-256 ECB.

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
*/
void encrypt(Byte *buffer, int buf_len, const std::string &password);

/*
    Decrypts a buffer in place using AES-256.
    [In]:
        * buffer - ptr to a buffer of bytes.
        * buf_len - size of the buffer.
        * password - password used to encrypt the buffer.
*/
void decrypt(Byte *buffer, int buf_len, const std::string &password);

/*
    Prepares the buffer for encryption.
    Assumes buffer has enough space and is not a nullptr.

    Adds padding to a buffer so that AES can be applied properly.
*/
void add_padding(Byte *buffer, int buf_size, int pad_len);

/*
    Removes padding from the decrypted buffer.

    [Input]:
    * new_size - length of the buffer not including padding bytes.
*/
void remove_padding(Byte *buffer, int buf_size, int *new_size);

#endif
