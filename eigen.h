//
// Created by Roye on 12/08/2020.
//

#ifndef SW_PROJECT_EIGEN_H
#define SW_PROJECT_EIGEN_H
#include <stdio.h>
#include <stdlib.h>


void printMatrix(double **matrix, int numberOfRows, int numberOfColumns);
void printVector(int length, double *vector);
void normalizeVector(int length, double *vector);
void printVectorToFile(int length,double *vector, FILE *file);
double* generateRandomVector(int length);
double* multiplyMatrixAndVector(double** matrix, double* vector, double* newVector, int length);
int hasEpsilonDifference(double* vector, double* oldVector, int length);
void iterate(double** matrix, double* vector, double* newVector, int length);


#endif //SW_PROJECT_EIGEN_H
