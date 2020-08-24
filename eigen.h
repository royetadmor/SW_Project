/*
 * Created by Roye on 12/08/2020.
 */

#ifndef SW_PROJECT_EIGEN_H
#define SW_PROJECT_EIGEN_H
#include <stdio.h>
#include <stdlib.h>


void printVectorToFile(int length,double *vector, FILE *file);
double* generateRandomVector(int length);
int hasEpsilonDifference(double* vector, double* oldVector, int length);
void iterate(double** matrix, double* vector, double* newVector, int length);


#endif /*SW_PROJECT_EIGEN_H*/
