file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${relearning_cpp_SOURCE_DIR}/include/utils/*.hh")

add_library(utils utils.cc ${HEADER_LIST})

target_include_directories(utils PUBLIC ../../include)
