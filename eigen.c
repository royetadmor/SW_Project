#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "MatrixAndVectorOps.h"



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

int iterate(double** matrix, double* vector, double* newVector, int length){
	multiplyMatrixAndVector(matrix,vector,newVector,length);
	normalizeVector(length,newVector);
	/*printVector(length,newVector);*/
	multiplyMatrixAndVector(matrix,newVector,vector,length);
	normalizeVector(length,vector);
	/*printVector(length,vector);*/
	return EXIT_SUCCESS;
}











