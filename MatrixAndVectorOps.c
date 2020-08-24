/*
* Created by Roye on 18/08/2020.
*/

#include "MatrixAndVectorOps.h"
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


double* multiplyMatrixAndVector(double** matrix, double* vector, double* newVector, int length){
    int i,j;
    int sum;
    for(i = 0 ; i < length; i++){
        sum = 0;
        for(j = 0 ; j < length; j++){
            sum += (matrix[i][j]*vector[j]);
        }
        newVector[i] = sum;
    }
    return newVector;
}


void normalizeVector(int length, double *vector){
    int i;
    long double	sum = 0;
    for(i = 0; i < length; i++){
        sum += vector[i]*vector[i];
    }
    sum = sqrt(sum);
    for(i = 0; i < length; i++){
        vector[i] = vector[i]/sum;
    }
}


double MultiplyVectorAndVector(double* vector1, double* vector2, int length)
{
    double sum = 0;
    int i;
    for (i = 0; i < length; ++i) {
        sum += vector1[i]*vector2[i];
    }
    return sum;
}


void printMatrix(double **matrix, int numberOfRows, int numberOfColumns){
    int i ,j;
    for (i = 0 ; i < numberOfRows; i ++){
        for(j = 0 ; j < numberOfColumns; j++){
            printf("%10.1f ",*(*(matrix + i)+j) );
        }
        printf("\n");
    }
}
void printVector(int length, double *vector){
    int i;
    for(i = 0; i < length; i++){
        printf("%15.10f ",vector[i]);
    }
    printf("\n");
}


double* generateRandomVector(int length){
    int i;
    double* vectorToReturn = (double*)malloc(sizeof(double)*length);
    srand(time(NULL));
    for(i = 0 ; i < length; i++){
        vectorToReturn[i] = rand();
    }
    return vectorToReturn;
}
<<<<<<< HEAD


void printIntMat(int **mat, int length){
	int i = 0 , j = 0;
	for (; i < length; i++){
		for(; j < length; j++){
			printf("%6d ",*(*(mat + i)+j) );
		}
		j = 0;
		printf("\n");
	}
	i = 0;
}


void printDoubleMat(double **mat, int length){
	int i = 0 , j = 0;
	for (; i < length; i++){
		for(; j < length; j++){
			printf("%+.3f ",*(*(mat + i)+j) );
		}
		j = 0;
		printf("\n");
	}
	i = 0;
}


