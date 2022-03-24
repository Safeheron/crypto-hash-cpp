find_package(GTest REQUIRED)

add_executable(hash-test hash-test.cpp)
target_include_directories(hash-test PRIVATE
        "../src"
        ${GTEST_INCLUDE_DIRS}
        )
target_link_libraries( hash-test
        CryptoHash
        ${GTEST_BOTH_LIBRARIES}
        pthread )
add_test(NAME hash-test COMMAND hash-test)