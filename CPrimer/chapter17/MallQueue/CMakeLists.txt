cmake_minimum_required(VERSION 3.8)
project(MallQueue)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES queue.h)
set(SOURCE_FILES queue.c mall.c)
add_executable(MallQueue ${SOURCE_FILES})