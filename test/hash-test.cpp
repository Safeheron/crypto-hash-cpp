//
// Created by Sword03 on 2020/10/22.
//
#include "gtest/gtest.h"
#include "../src/crypto-hash/sha256.h"
using safeheron::hash::CSHA256;

static const char *sha2_hex_digits = "0123456789abcdef";

void bytes2hex(const uint8_t * input, size_t input_len, char * output, size_t output_len){
    assert(output_len == 2 * input_len + 1);
    const uint8_t *d = input;
    char *buffer = output;
    for (int i = 0; i < input_len; i++) {
        *buffer++ = sha2_hex_digits[(*d & 0xf0) >> 4];
        *buffer++ = sha2_hex_digits[*d & 0x0f];
        d++;
    }
    *buffer = (char)0;
}

std::vector<std::vector<std::string>> test_case_for_sha256 = {
        {
            "",
            "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
        },
};

void run_case(const uint8_t * input, size_t  input_len, const char * expected_digest_hex){
    CSHA256 sha256;
    uint8_t digest[CSHA256::OUTPUT_SIZE];
    sha256.Write(input, input_len);
    sha256.Finalize(digest);

    char digest_hex[CSHA256::OUTPUT_SIZE * 2 + 1];
    bytes2hex(digest, CSHA256::OUTPUT_SIZE, digest_hex, CSHA256::OUTPUT_SIZE * 2 + 1);

    EXPECT_TRUE(strcmp(expected_digest_hex, digest_hex) == 0);
}

TEST(HASH, SHA256)
{
    for(const auto &data: test_case_for_sha256) {
        const uint8_t * input = reinterpret_cast<const uint8_t *>(data[0].c_str());
        size_t  input_len = data[0].length();
        const char * expected_digest_hex = data[1].c_str();
        run_case(input, input_len, expected_digest_hex);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
