cmake_minimum_required(VERSION 3.21)
set(TARGET algorithms_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ../include)

set(PROJECT_INCLUDE_DIR
    ${INCLUDE_DIR}
    ${INCLUDE_DIR}/containers
    ${INCLUDE_DIR}/search
    ${INCLUDE_DIR}/sorting)

include_directories(${PROJECT_INCLUDE_DIR})

file(GLOB PROJECT_SOURCES
    containers/*.cpp
    search/*.cpp
    sorting/*.cpp)

add_executable(${TARGET} ${PROJECT_SOURCES})

target_link_libraries(${TARGET} PUBLIC gtest_main)

add_test(NAME ${TARGET} COMMAND ${TARGET})
