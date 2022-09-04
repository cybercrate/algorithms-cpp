cmake_minimum_required(VERSION 3.20)

if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{HOMEPATH}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(algorithms VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package(GTest CONFIG REQUIRED)

add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIRS})

add_subdirectory(test)
target_include_directories("${PROJECT_NAME}_test" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/test")
target_link_libraries("${PROJECT_NAME}_test" PRIVATE GTest::gtest_main ${PROJECT_NAME})
