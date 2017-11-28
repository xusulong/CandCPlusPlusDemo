cmake_minimum_required(VERSION 3.8)
project(BinaryTree)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES tree.h tree.c petclub.c)
add_executable(BinaryTree ${SOURCE_FILES})