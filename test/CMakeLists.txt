cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories("../src")

add_executable(hash-test hash-test.cpp)
target_link_libraries( hash-test
        CryptoHash
        ${GTEST_BOTH_LIBRARIES}
        pthread )
add_test(NAME test-hash COMMAND hash-test)