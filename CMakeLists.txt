cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(LIB_ERR_FUSION lib/err-fusion)

include_directories(${LIB_ERR_FUSION}/include)

add_subdirectory(lib/googletest)
add_subdirectory(test)
