#ifndef SW_PROJECT_MATRIXANDVECTOROPS_H
#define SW_PROJECT_MATRIXANDVECTOROPS_H

double* multiplyMatrixAndVector(double** matrix, double* vector, double* newVector, int length);
void normalizeVector(int length, double *vector);
double MultiplyVectorAndVector(double* vector1, double* vector2, int length);
void printVector(int length, double *vector);
double* generateRandomVector(int length);
void printIntMat(int **mat, int length);
void printDoubleMat(double **mat, int length);
void printIntVector(int length, int *vector);
void freeDoubleMatrix(double** matrix, int length);
void freeIntMatrix(int** matrix, int length);


#endif /*SW_PROJECT_MATRIXANDVECTOROPS_H*/
