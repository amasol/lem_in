cmake_minimum_required(VERSION 3.12)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)

#include_directories(Lem_in libft)

AUX_SOURCE_DIRECTORY(libft LIBA)

add_executable(Lem_in
        ${LIBA}
        lem_in.h
        main.c
        parsing.c
        error.c)

link_libraries(libft/libftprintf.a)