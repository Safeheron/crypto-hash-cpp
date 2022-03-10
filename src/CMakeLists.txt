cmake_minimum_required(VERSION 3.10)
project(CryptoHash)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")

add_library(${PROJECT_NAME} SHARED
        crypto-hash/sha1.cpp
        crypto-hash/sha256.cpp
        crypto-hash/sha512.cpp
        crypto-hash/ripemd160.cpp
        crypto-hash/chacha20.cpp
        crypto-hash/hmac_sha256.cpp
        crypto-hash/hmac_sha512.cpp
        )

include(CheckIncludeFileCXX)

# Check if file endian.h, byteswap.h, sys/endian.h exist.
CHECK_INCLUDE_FILE_CXX("endian.h" HAVE_ENDIAN_H)
CHECK_INCLUDE_FILE_CXX("byteswap.h" HAVE_BYTESWAP_H)
CHECK_INCLUDE_FILE_CXX("sys/endian.h" HAVE_SYS_ENDIAN_H)

if(HAVE_ENDIAN_H EQUAL 1)
    target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_ENDIAN_H)
endif()

if(HAVE_BYTESWAP_H EQUAL 1)
    target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_BYTESWAP_H)
endif()

if(HAVE_SYS_ENDIAN_H EQUAL 1)
    target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_SYS_ENDIAN_H)
endif()
# End check
