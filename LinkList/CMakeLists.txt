cmake_minimum_required(VERSION 3.8)
project(demo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp linkList/linklist.h linkList/linklist.cpp)
add_executable(demo ${SOURCE_FILES})