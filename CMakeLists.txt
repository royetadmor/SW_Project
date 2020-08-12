cmake_minimum_required(VERSION 3.15)
project(SW_project C)

set(CMAKE_C_STANDARD 90)

add_executable(SW_project main.c cov.c eigen.c spmat.c)