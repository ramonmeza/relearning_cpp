file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${relearning_cpp_SOURCE_DIR}/include/utils/*.hh")
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${relearning_cpp_SOURCE_DIR}/src/utils/*.cc")

add_library(utils ${SRC_FILES} ${HEADER_LIST})

target_include_directories(utils PUBLIC ../../include)
