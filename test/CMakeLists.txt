file(GLOB PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp")

add_executable("${PROJECT_NAME}_test" ${PROJECT_SOURCES})

target_include_directories("${PROJECT_NAME}_test" PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_INCLUDE_DIRS})

target_link_libraries("${PROJECT_NAME}_test" PRIVATE GTest::gtest_main)

enable_testing()
add_test(NAME "${PROJECT_NAME}_test" COMMAND "${PROJECT_NAME}_test")
