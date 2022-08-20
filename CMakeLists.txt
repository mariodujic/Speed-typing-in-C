cmake_minimum_required(VERSION 3.23)
project(speed_type C)

set(CMAKE_C_STANDARD 99)
set(Headers definitions.h dictionary.h utils.h file_reader.h timer.h)
set(Sources dictionary.c utils.c file_reader.c timer.c)

add_executable(speed_type main.c ${Headers} ${Sources})
