aux_source_directory(. DIR_HELLO_SRCS)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(../)
add_library(developer ${DIR_HELLO_SRCS})