cmake_minimum_required(VERSION 2.9)
project(calf CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CALF_STATIC_LIBRARY_NAME ${PROJECT_NAME}Static)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)
add_library(${PROJECT_NAME} SHARED ${SRCS})
add_library(${CALF_STATIC_LIBRARY_NAME} STATIC ${SRCS})

#file(GLOB_RECURSE LIB_HEADER_FILES ./include/*.hpp)

set(PC_LIB ${PROJECT_NAME})
configure_file(./resources/${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}Static
        LIBRARY DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/calf DESTINATION include)
install(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION lib/pkgconfig)

