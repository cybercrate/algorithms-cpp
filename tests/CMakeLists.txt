cmake_minimum_required(VERSION 3.20)
set(TARGET algorithms_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROJECT_SOURCES
    "containers/*.cpp"
    "search/*.cpp"
    "sorting/*.cpp"
    "strings/*.cpp")

add_executable(${TARGET} ${PROJECT_SOURCES})

target_link_libraries(${TARGET} PUBLIC
    gtest_main
    algorithms
    test_helpers)

target_include_directories(${TARGET} PUBLIC "../include")

enable_testing()
add_test(NAME ${TARGET} COMMAND ${TARGET})
