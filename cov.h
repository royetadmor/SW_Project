//
// Created by Roye on 12/08/2020.
//

#ifndef SW_PROJECT_COV_H
#define SW_PROJECT_COV_H
#include <stdio.h>
#include <stdlib.h>

void createCovMatrix(double **covMatrix ,double **matrix, int numberOfRows, int numberOfColumns);
void printMatrixToFile(int numberOfRows,int numberOfColumns,double **matrix, FILE *file);

#endif //SW_PROJECT_COV_H
