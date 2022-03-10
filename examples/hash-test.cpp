//
// Created by Sword03 on 2020/10/22.
//
#include <string.h>
#include <crypto-hash/sha256.h>

using safeheron::hash::CSHA256;

int main(int argc, char **argv) {
    const char *input = "";
    size_t input_len = strlen(input);
    const char *output = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";

    CSHA256 sha256;
    uint8_t digest[CSHA256::OUTPUT_SIZE];
    sha256.Write((const uint8_t *)input, input_len);
    sha256.Finalize(digest);

    return 0;
}
