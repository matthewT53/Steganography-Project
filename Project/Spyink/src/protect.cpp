#include <iostream>

#include "headers/protect.h"
#include "headers/aes.h"
#include "headers/sha256.h"

void encrypt(Byte *buffer, int buf_len, const std::string &password)
{
    std::cout << "Encrypting buffer." << std::endl;
    std::string key = sha256(password);
    std::cout << "Password hash: " << key << std::endl;

    struct AES_ctx *ctx = new AES_ctx;
    AES_init_ctx(ctx, (const uint8_t *) key.c_str());

    for (int i = 0; i < buf_len; i += AES_BLOCKLEN){
        AES_ECB_encrypt(ctx, buffer + i);
        std::cout << "i = " << i << std::endl;
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
