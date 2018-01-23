#include <iostream>

#include "headers/protect.h"
#include "headers/aes.h"
#include "headers/sha256.h"

// need to re-size buffer to be a multiple of 16
void encrypt(Byte *buffer, int buf_len, const std::string &password)
{
    std::cout << "Encrypting buffer." << std::endl;
    std::string key = sha256(password);
    std::cout << "Password hash: " << key << std::endl;

    struct AES_ctx *ctx = new AES_ctx;
    AES_init_ctx(ctx, (const uint8_t *) key.c_str());

    for (int i = 0; i < buf_len; i += AES_BLOCKLEN){
        AES_ECB_encrypt(ctx, buffer + i);
    }

    std::cout << "Finished encryption." << std::endl;

    delete ctx;
}

void decrypt(Byte *buffer, int buf_len, const std::string &password)
{
    std::cout << "Decrypting buffer." << std::endl;
    std::string key = sha256(password);
    std::cout << "Password hash: " << key << std::endl;

    struct AES_ctx *ctx = new AES_ctx;
    AES_init_ctx(ctx, (const uint8_t *) key.c_str());

    for (int i = 0; i < buf_len; i += AES_BLOCKLEN){
        AES_ECB_decrypt(ctx, buffer + i);
    }

    delete ctx;
}

void add_padding(Byte *buffer, int buf_size, int pad_len)
{
    std::cout << "Padding lenth: " << pad_len << std::endl;
    for (int i = 0; i < pad_len; i++){
        buffer[buf_size-1-i] = static_cast<Byte>(pad_len);
    }
}

void remove_padding(Byte *buffer, int buf_size, int *new_size)
{
    int pad_char = buffer[buf_size - 1];
    int same_byte_count = 0;

    for (int i = 0; i < pad_char; i++){
        if (buffer[buf_size-1-i] == pad_char){
            same_byte_count++;
        }

        else{
            break;
        }
    }

    if (same_byte_count == pad_char){
        *new_size = buf_size - same_byte_count;
    }

    else{
        *new_size = buf_size;
    }
}
