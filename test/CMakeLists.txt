cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES
    search/binary_search_tests.cpp)

add_executable(algorithms_test ${SOURCE_FILES})

target_link_libraries(algorithms_test PUBLIC
    gtest_main
    algorithms)

add_test(
    NAME algorithms_test
    COMMAND algorithms_test)