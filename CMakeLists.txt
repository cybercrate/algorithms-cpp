cmake_minimum_required(VERSION 3.20)

project(algorithms VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++20 -Werror -Wall -Wextra -Wpedantic")

set(PROJECT_INCLUDE_DIRS
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/lib/wing-concepts/include")

find_package(GTest CONFIG REQUIRED)

add_subdirectory(test)
