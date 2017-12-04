cmake_minimum_required(VERSION 3.8)
project(BTree)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Tree.h Tree.c fatal.h)
add_executable(BTree ${SOURCE_FILES})