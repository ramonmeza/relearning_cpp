cmake_minimum_required(VERSION 3.25)

project(
    relearning_cpp
    DESCRIPTION "My attempt at relarning C++ using the book by 'C++ Programming for Games' by Frank Luna."
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(app)

# google tests
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
    set(PACKAGE_TESTS ON)
endif()

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    include(GoogleTest)
    add_subdirectory(tests)
endif()
