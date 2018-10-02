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
        error.c
        add_func.c
        save_room.c
        arr_len.c
        parsing_help.c
        comparison.c
        error_help.c
        save_room_link.c
        save_map.c
        algorithm.c
        ft_list_size.c
        output.c)

link_libraries(libft/libftprintf.a)