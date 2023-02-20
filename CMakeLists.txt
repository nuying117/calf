cmake_minimum_required(VERSION 2.9)
project(calf CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(src SRCS)
add_library(${PROJECT_NAME} SHARED ${SRCS})
add_library(${PROJECT_NAME}Static STATIC ${SRCS})

file(GLOB_RECURSE LIB_HEADER_FILES ./include/*.hpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${LIB_HEADER_FILES})

set(PC_LIB ${PROJECT_NAME})
configure_file(./resources/${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}Static
        PUBLIC_HEADER DESTINATION include/${PROJECT_NAME}
        LIBRARY DESTINATION lib)
install(FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION lib/pkgconfig)
