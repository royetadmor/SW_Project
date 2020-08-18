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


//void printMatrix(double **matrix, int numberOfRows, int numberOfColumns){
//	int i ,j;
//	for (i = 0 ; i < numberOfRows; i ++){
//		for(j = 0 ; j < numberOfColumns; j++){
//			printf("%10.1f ",*(*(matrix + i)+j) );
//		}
//		printf("\n");
//	}
//}
//
//void printVector(int length, double *vector){
//	int i;
//	for(i = 0; i < length; i++){
//		printf("%15.10f ",vector[i]);
//	}
//	printf("\n");
//}


//void normalizeVector(int length, double *vector){
//	int i;
//	long double	sum = 0;
//	for(i = 0; i < length; i++){
//		sum += vector[i]*vector[i];
//	}
//	sum = sqrt(sum);
//	for(i = 0; i < length; i++){
//		vector[i] = vector[i]/sum;
//	}
//}


void printVectorToFile(int length,double *vector, FILE *file){
	int j = 1;
	assert(length!= 0);
	assert(vector!= NULL);
	assert(file!=NULL);
	fwrite(&j, sizeof(int), 1, file); /* columns */
	fwrite(&length, sizeof(int), 1, file); /* rows */
	fwrite(vector, sizeof(double), length, file); /* the vector */
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



//int main(int argc, char* argv[]) {
//	/*clock_t start = clock();*/
//
//
//	/* the 1st argument (input filename) with argv[1],
//	the 2nd argument (output filename) with argv[2]. */
//
//
//
//
//	/*-----------------------------------declarations-----------------------------------*/
//
//
//	char *inFile, *outFile;
//	FILE *file ;
//	int numberOfColumns = 0; /* 1st argument in the file */
//	int numberOfRows = 0; /* 2st argument in the file */
//	double *vector, *newVector;
//	double **matrix;
//	int ass = 0;
//	int i, j;
//	/*clock_t end;
//	double delta;*/
//
//
//
//
//
//
//	/*-----------------------------------code-----------------------------------*/
//	assert(argc == 0 || argc != 0);
//	assert(argv[1] != NULL);
//	inFile = argv[1];
//	assert(argv[2] != NULL);
//	outFile = argv[2];
//	file = fopen(inFile, "r");
//	assert(file!=NULL);
//	ass = fread(&numberOfColumns, sizeof(int), 1, file);
//	assert(ass == 1);
//	ass = fread(&numberOfRows, sizeof(int), 1, file);
//	assert(ass == 1);
//
//	matrix = (double **)calloc(numberOfRows , sizeof(double*));
//	for(i = 0; i < numberOfRows; i++) {
//		matrix[i] = (double *)calloc(numberOfColumns , sizeof(double));
//	}
//
//	for (i = 0 ; i < numberOfRows; i ++){
//		for(j = 0 ; j < numberOfColumns; j++){
//			ass = fread(&(matrix[i][j]), sizeof(double), 1, file);
//			assert(ass == 1);
//		}
//	}
//
//	fclose(file);
//	/*printf("The original matrix:\n");
//	printMatrix(matrix,numberOfRows,numberOfColumns);*/
//			/*-------------------- finished to receive the input matrix   -------------*/
//
//	vector = generateRandomVector(numberOfRows);
//	normalizeVector(numberOfRows,vector);
//
//	/*printf("The random generated vector:\n");
//	printVector(numberOfRows,vector);*/
//
//
//	newVector = (double*)malloc(sizeof(double)*numberOfRows);
//
//
//	do{
//		iterate(matrix,vector,newVector,numberOfRows);
//		i = hasEpsilonDifference(vector,newVector,numberOfRows);
//	}
//	while(i == 0);
//	/*printf("old vector::\n");
//	printVector(numberOfRows,newVector);
//	printf("new vector:\n");
//	printVector(numberOfRows,vector);*/
//
//
//			/*-------------------- start to print the vector to the output file   -------------*/
//
//	file = fopen(outFile, "w");
//	assert(file!=NULL);
//	printVectorToFile(numberOfRows,vector,file);
//	fclose(file);
//	/*end = clock();
//	delta = ((double)(end-start) / CLOCKS_PER_SEC);*/
//	/*printf("the delta: %15.8f\n",delta);*/
//
//
//
//
//	/*-------------------- free memory   -------------*/
//	free(vector);
//	free(newVector);
//	free(matrix);
//
//
//	return EXIT_SUCCESS;
//
//}
//
//







