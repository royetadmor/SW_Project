/*
 ============================================================================
 Name        : W.c
 Author      : ht
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "MatrixAndVectorOps.h"




void printVectorToFile(int length,double *vector, FILE *file){
	int j = 1;
	assert(length!= 0);
	assert(vector!= NULL);
	assert(file!=NULL);
	fwrite(&j, sizeof(int), 1, file); /* columns */
	fwrite(&length, sizeof(int), 1, file); /* rows */
	fwrite(vector, sizeof(double), length, file); /* the vector */
}


/* the function return 1 if the difference between each corresponding pair of values is less then Epsilon */
int hasEpsilonDifference(double* vector, double* oldVector, int length){
	int i;
	double EPSILON = 0.00001;
	for(i =0 ; i < length ; i++){
		if(EPSILON <= fabs(vector[i]-oldVector[i])){
			return 0;
		}
	}
	return 1;
}

void iterate(double** matrix, double* vector, double* newVector, int length){
	multiplyMatrixAndVector(matrix,vector,newVector,length);
	normalizeVector(length,newVector);
	/*printVector(length,newVector);*/
	multiplyMatrixAndVector(matrix,newVector,vector,length);
	normalizeVector(length,vector);
	/*printVector(length,vector);*/
}











