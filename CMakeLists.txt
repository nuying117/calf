cmake_minimum_required(VERSION 2.6)
project(calf CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(src SRCS)
add_library(${PROJECT_NAME} SHARED ${SRCS})

