file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${relearning_cpp_SOURCE_DIR}/include/exercises/*.hh")

add_library(exercises chapter_01.cc chapter_02.cc chapter_03.cc ${HEADER_LIST})

target_include_directories(exercises PUBLIC ../../include)
target_link_libraries(exercises PRIVATE utils)
