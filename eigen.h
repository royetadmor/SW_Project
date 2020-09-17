#ifndef SW_PROJECT_EIGEN_H
#define SW_PROJECT_EIGEN_H
#include <stdio.h>
#include <stdlib.h>



/**
 * the function return 1 if the difference between each corresponding pair of values is less then Epsilon
 */
int hasEpsilonDifference(double* vector, double* oldVector, int length);

int iterate(double** matrix, double* vector, double* newVector, int length);


#endif /*SW_PROJECT_EIGEN_H*/
