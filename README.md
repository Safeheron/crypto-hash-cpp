# crypto-hash-cpp

![img](doc/logo.png)

Hash implementation in C++, such as sha1, sha256, sha512, ripemd160, hash160, hash256, hmac_sha256, hmac_sha512 and chacha20 .

# Build and Install

Linux and Mac are supported now.  After obtaining the Source, have a look at the installation script.

```shell
git clone https://github.com/safeheron/crypto-hash-cpp.git
cd crypto-hash-cpp
mkdir build && cd build
cmake ..
cmake
make test
sudo make install
```

More platforms such as Windows would be supported soon.


# To start using crypto-hash-cpp

## CMake

CMake is your best option. It supports building on Linux, MacOS and Windows (soon) but also has a good chance of working on other platforms (no promises!). cmake has good support for crosscompiling and can be used for targeting the Android platform.

To build crypto-bn-cpp from source, follow the BUILDING guide.

The canonical way to discover dependencies in CMake is the find_package command.

```shell
project(XXXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")

find_package(CryptoHash REQUIRED)

add_executable(${PROJECT_NAME} XXXX.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CryptoHash_INCLUDE_DIRS}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        CryptoHash
        )
```

## Example

```c++
#include "crypto-hash/sha256.h"

using safeheron::hash::CSHA256;

int main(){
    std::string input = "";
    std::string expected_digest_hex = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";
    CSHA256 sha256;
    uint8_t digest[CSHA256::OUTPUT_SIZE];
    sha256.Write((uint_8 *)input.c_str(), input.size());
    sha256.Finalize(digest);

    std::string digest_hex = bytes2hex(digest, CSHA256::OUTPUT_SIZE);
    EXPECT_TRUE(strcmp(expected_digest_hex, digest_hex.c_str()) == 0);
    
    return 0;
}
```

# Usage

#### Class - safeheron::hash::CSHA1
>- CSHA1() - Constructor
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
>- Reset() - Reset the hash status.

#### Class - safeheron::hash::CSHA256
>- CSHA256() - Constructor
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
>- Reset() - Reset the hash status.

#### Class - safeheron::hash::CSHA512
>- CSHA512() - Constructor
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
>- Reset() - Reset the hash status.

#### Class - safeheron::hash::CRIPEMD160
>- CRIPEMD160() - Constructor
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
>- Reset() - Reset the hash status.

#### Class - safeheron::hash::Hash160
>- CHash160() - Constructor
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
>- Reset() - Reset the hash status.

#### Class - safeheron::hash::Hash256
>- CHash256() - Constructor
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
>- Reset() - Reset the hash status.

#### Class - safeheron::hash::CHMAC_SHA256
>- CHMAC_SHA256(const unsigned char* key, size_t keylen) - Constructor with key.
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.

#### Class - safeheron::hash::CHMAC_SHA512
>- CHMAC_SHA512(const unsigned char* key, size_t keylen) - Constructor with key.
>- Write(const unsigned char *data, size_t len) - Update hash status with input data.
>- Finalize(unsigned char hash[OUTPUT_SIZE]) - Output the digest.
 
# Some parts of the library come from external sources:
- Bitcoin Core:[https://github.com/bitcoin/bitcoin.git](https://github.com/bitcoin/bitcoin.git)

# Development Process & Contact
This library is maintained by Safeheron. Contributions are highly welcomed! Besides GitHub issues and PRs, feel free to reach out by mail or join Safeheron Telegram for discussions on code and research.

# License
