cmake_minimum_required(VERSION 3.8)
project(filmlist)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c list.h list.c)
add_executable(filmlist ${SOURCE_FILES})