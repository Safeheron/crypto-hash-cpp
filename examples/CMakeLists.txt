cmake_minimum_required(VERSION 3.10)
project(example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(CryptoHash REQUIRED)
if(CryptoHash_FOUND )
    MESSAGE(STATUS "Found CryptoHash!")
endif(CryptoHash_FOUND )

add_executable(hash-test hash-test.cpp)
target_include_directories(hash-test PUBLIC
        ${CryptoHash_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries( hash-test PUBLIC
        CryptoHash
        ${GTEST_BOTH_LIBRARIES}
        pthread )