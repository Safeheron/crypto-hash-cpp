cmake_minimum_required(VERSION 3.10)

project("CryptoHash" VERSION 1.0.1)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

include("cmake/setup_installation.cmake")