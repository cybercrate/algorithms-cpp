cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES
    search/*.cpp)

add_executable(wingalgo_test ${SOURCE_FILES})

target_link_libraries(wingalgo_test PUBLIC gtest_main)

add_test(
    NAME wingalgo_test
    COMMAND wingalgo_test)