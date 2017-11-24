cmake_minimum_required(VERSION 3.8)
project(Queue)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES queue.h queue.c use_q.c)
add_executable(Queue ${SOURCE_FILES})