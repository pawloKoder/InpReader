cmake_minimum_required(VERSION 2.8)

project(inpreader)

set (CMAKE_CXX_FLAGS "-Wall -std=c++11")
set (CMAKE_BUILD_TYPE Debug)

include_directories (${inpreader_SOURCE_DIR}/src)

set (EXECUTABLE_OUTPUT_PATH "${inpreader_BINARY_DIR}/bin")
set (LIBRARY_OUTPUT_PATH "${inpreader_BINARY_DIR}/lib")

add_subdirectory (src)