#ifndef SW_PROJECT_COV_H
#define SW_PROJECT_COV_H
#include <stdio.h>
#include <stdlib.h>

int createCovMatrix(double **covMatrix ,double **matrix, int numberOfRows, int numberOfColumns);
int printMatrixToFile(int numberOfRows,int numberOfColumns,double **matrix, FILE *file);

#endif //SW_PROJECT_COV_H
