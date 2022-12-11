enable_testing()

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_executable(
    utils_unittests
    utils_unittests.cc
)

target_link_libraries(
    utils_unittests
    PUBLIC
    gtest
    gmock
    gtest_main
    PRIVATE
    utils
)

gtest_discover_tests(utils_unittests)

add_test(utils_unittests utils_unittests)
