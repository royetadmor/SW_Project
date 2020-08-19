/*
* Created by Roye on 18/08/2020.
*/

#ifndef SW_PROJECT_MATRIXANDVECTOROPS_H
#define SW_PROJECT_MATRIXANDVECTOROPS_H

double* multiplyMatrixAndVector(double** matrix, double* vector, double* newVector, int length);
void normalizeVector(int length, double *vector);
double MultiplyVectorAndVector(double* vector1, double* vector2, int length);
void printMatrix(double **matrix, int numberOfRows, int numberOfColumns);
void printVector(int length, double *vector);
double* generateRandomVector(int length);

#endif /*SW_PROJECT_MATRIXANDVECTOROPS_H*/
