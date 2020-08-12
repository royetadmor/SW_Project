cmake_minimum_required(VERSION 3.15)
project(SW_project C)

set(CMAKE_C_STANDARD 90)

add_executable(SW_project cov.c eigen.c spmat.c cov.h eigen.h Algorithem1.c Algorithem1.h sparse.c sparse.h)