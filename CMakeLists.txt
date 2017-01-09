cmake_minimum_required(VERSION 3.6)
project(test1)

set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES main.c)
#set(SOURCE_FILES swap.c)
#set(SOURCE_FILES getint.c)
#set(SOURCE_FILES getint_0.c)
#set(SOURCE_FILES getfloat.c)
set(SOURCE_FILES strlen.c)
add_executable(test1 ${SOURCE_FILES})