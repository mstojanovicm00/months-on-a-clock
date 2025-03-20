cmake_minimum_required(VERSION 3.23)
project(Months_on_a_Clock C)

set(CMAKE_C_STANDARD 99)

add_executable(Months_on_a_Clock main.c month.c month.h clock.c clock.h)
