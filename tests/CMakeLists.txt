find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        message(STATUS ${GIT_SUBMOD_RESULT})
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

add_executable(
    utils_unittests
    utils_unittests.cc
)

target_link_libraries(
    utils_unittests
    PUBLIC
    GTest::gtest
    GTest::gmock
    GTest::gtest_main
    PRIVATE
    utils
)

gtest_discover_tests(utils_unittests)

add_test(utils_unittests utils_unittests)
