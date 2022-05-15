find_package(GTest REQUIRED)

include_directories("../src"
        ${GTEST_INCLUDE_DIRS})

option(ENABLE_ASSEMBLE "Enable assemble" OFF)
if (NOT ${ENABLE_ASSEMBLE})
    link_libraries(CryptoHash
            ${GTEST_BOTH_LIBRARIES}
            ${PROTOBUF_LIBRARY_DIRS}
            pthread )
else()
    link_libraries(${CMAKE_PROJECT_NAME}
            ${GTEST_BOTH_LIBRARIES}
            ${PROTOBUF_LIBRARY_DIRS}
            pthread )
endif()

add_executable(hash-test hash-test.cpp)
add_test(NAME hash-test COMMAND hash-test)