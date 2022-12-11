file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${relearning_cpp_SOURCE_DIR}/include/exercises/*.hh")
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${relearning_cpp_SOURCE_DIR}/src/exercises/*.cc")

add_library(exercises ${SRC_FILES} ${HEADER_LIST})

target_include_directories(exercises PUBLIC ../../include)
target_link_libraries(exercises PRIVATE utils)
