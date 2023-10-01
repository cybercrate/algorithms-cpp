cmake_minimum_required(VERSION 3.20)

if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{HOMEPATH}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(algorithms)

if (MSVC)
    set(CMAKE_CXX_FLAGS "/std:c++20")
else()
    set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Wextra -Wpedantic")
endif()

set(PROJECT_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include")

find_package(GTest CONFIG REQUIRED)

add_subdirectory(test)
