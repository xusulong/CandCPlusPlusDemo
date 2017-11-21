cmake_minimum_required(VERSION 3.8)
project(List)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c list.h list.c fatal.h)
add_executable(List ${SOURCE_FILES})