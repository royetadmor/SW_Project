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
#include <time.h>
#include "MatrixAndVectorOps.h"


void createCovMatrix(double **covMatrix ,double **matrix, int numberOfRows, int numberOfColumns){
	int i, j ,k;
	double tmp;

	for ( i = 0 ; i < numberOfRows; i ++){
		for(k = i ; k < numberOfRows ; k++){
			tmp = 0;
			for(j = 0 ; j < numberOfColumns; j++){
				tmp += matrix[i][j]*matrix[k][j];
			}
			covMatrix[i][k] =tmp;
		}
	}
	for(i = 0; i < numberOfRows ; i++){
		for(j = 0; j < i; j++){
			covMatrix[i][j]= covMatrix[j][i];
		}
	}
}


void printMatrixToFile(int numberOfRows,int numberOfColumns,double **matrix, FILE *file){
	int i;

	assert(numberOfRows!= 0);
	assert(numberOfColumns!= 0);
	assert(matrix!= NULL);
	assert(file!=NULL);

	fwrite(&numberOfColumns, sizeof(int), 1, file);
	fwrite(&numberOfRows, sizeof(int), 1, file);
	for(i = 0 ; i < numberOfRows; i++){
		fwrite(matrix[i], sizeof(double), numberOfColumns, file);
		/*assert(ass != numberOfColumns);*/
	}

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
//	char *inFile, *outFile;
//	FILE *file ;
//	int numberOfColumns = 0; /* 1st argument in the file */
//	int numberOfRows = 0; /* 2st argument in the file */
//	double **matrix ,**covMatrix;
//	int ass = 0;
//	int i, j;
//	/*clock_t end;
//	double delta;*/
//
//
//	/*-----------------------------------code-----------------------------------*/
//	assert(argc == 0 || argc != 0);
//
//	assert(argv[1] != NULL);
//	inFile = argv[1];
//	assert(argv[2] != NULL);
//	outFile = argv[2];
//
//
//	file = fopen(inFile, "r");
//	assert(file!=NULL);
//	ass = fread(&numberOfColumns, sizeof(int), 1, file);
//	assert(ass == 1);
//	ass = fread(&numberOfRows, sizeof(int), 1, file);
//	assert(ass == 1);
//
//
//	matrix = (double **)calloc(numberOfRows , sizeof(double*));
//	for(i = 0; i < numberOfRows; i++) {
//		matrix[i] = (double *)calloc(numberOfColumns , sizeof(double));
//	}
//
//	for (i = 0 ; i < numberOfRows; i ++){
//			long double sumOfRow = 0 ;
//			for(j = 0 ; j < numberOfColumns; j++){
//				ass = fread(&(matrix[i][j]), sizeof(double), 1, file);
//				assert(ass == 1);
//				sumOfRow += matrix[i][j];
//			}
//			sumOfRow = sumOfRow/numberOfColumns;
//			for(j = 0 ; j < numberOfColumns; j++){
//				matrix[i][j] -= sumOfRow;
//			}
//	}
//
//	fclose(file);
//
//	/*printf("The matrix after substruction of the mean from each line:\n");
//	printMatrix(matrix,numberOfRows,numberOfColumns);*/
//
//
//	covMatrix = (double **)calloc(numberOfRows , sizeof(double*));
//	for(i = 0; i < numberOfRows; i++) {
//		covMatrix[i] = (double *)calloc(numberOfRows , sizeof(double));
//	}
//	createCovMatrix(covMatrix ,matrix, numberOfRows, numberOfColumns);
//
//	/*printf("The covariance matrix:\n");
//	printMatrix(covMatrix,numberOfRows,numberOfRows);*/
//
//
//
//	file = fopen(outFile, "w");
//	assert(file!=NULL);
//	printMatrixToFile(numberOfRows,numberOfRows,covMatrix,file);
//	/*end = clock();*/
//	/*delta = ((double)(end-start) / CLOCKS_PER_SEC);*/
//	/*printf("the delta: %15.8f\n",delta);*/
//	free(matrix);
//	free(covMatrix);
//	return EXIT_SUCCESS;
//
//}









