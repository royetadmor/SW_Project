cmake_minimum_required(VERSION 3.15)
project(SW_project C)

set(CMAKE_C_STANDARD 90)

add_executable(SW_project cov.c eigen.c spmat.c cov.h eigen.h sparse.c modularity.c modularity.h sparse.h MathHelpers.c MathHelpers.h MatrixAndVectorOps.c MatrixAndVectorOps.h input.c Algorithms.c Algorithms.h cluster.c)