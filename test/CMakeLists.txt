cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ../include)

set(PROJECT_INCLUDE_DIRECTORIES
    ${INCLUDE_DIR}
    ${INCLUDE_DIR}/data_structures
    ${INCLUDE_DIR}/search)

include_directories(${PROJECT_INCLUDE_DIRECTORIES})

file(GLOB PROJECT_SOURCES
    search/*.cpp
    data_structures/*.cpp)

add_executable(wingalgo_test ${PROJECT_SOURCES})

target_link_libraries(wingalgo_test PUBLIC gtest_main)

add_test(NAME wingalgo_test COMMAND wingalgo_test)
