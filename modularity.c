/*
 * modularity.c
 *
 *  Created on: 18 Aug 2020
 *      Author: hadar
 */

/* include system packages */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>


/* remove later */

#include "input.c"
#include "MatrixAndVectorOps.c"
#include "List.h"
/* remove later */

int getModularityMatrix(double ***modMatrix, int length, int degreesSum, int* degreesArray, int**matrix){
	double **myMultMatrix = (double**)calloc(length, sizeof(double*));
	int i = 0 , j = 0;
	double multiplication = 0;

	for(; i < length; i++){
		myMultMatrix[i] = (double*)calloc(length, sizeof(double));
		for (; j < length; j++){
			multiplication = (double)(degreesArray[i] * degreesArray[j]);
			myMultMatrix[i][j] =  matrix[i][j] - (multiplication / (double)(degreesSum));
		}
		myMultMatrix[i][i] = 0;
		j = 0;
	}
	i = 0;

	*modMatrix = myMultMatrix;
	return EXIT_SUCCESS;
}

/**
 * i assume there is a least 1 node in the list
 */
int generateBTagMatrix(list *head, double ***BTagMatrix, double **modularityMatrix){

	int myBTagMatrixLength;
	double **myBTagMatrix ;

	myBTagMatrixLength = ListSize(head);
	myBTagMatrix = (double**)calloc(myBTagMatrixLength, sizeof(double*));

	printDoubleMat(*myBTagMatrix, myBTagMatrixLength);


	return EXIT_SUCCESS;

}



int main(int argc, char* argv[]) {


	/*-----------------------------------declarations-----------------------------------*/


	int **matrix = NULL;
	double **multMatrix = NULL;
	int *degreesArray = NULL;
	int degreesSum;
	int length;
	int ass;

	/* list *g; */

	/*-----------------------------------code-----------------------------------*/

	printf("Validating input existence ... \n");

	assert(argc != 0);
	assert(argv[1] != NULL);

	printf("There is input.\n");


	printf("Validating input existence ... \n");
	ass = getInputMatrix(argv[1], &length, &degreesSum, &degreesArray, &matrix);
	assert(ass == 0);

	ass = getModularityMatrix(&multMatrix, length, degreesSum , degreesArray, matrix);
	printDoubleMat(multMatrix, length);



	assert(ass == 0);


	return EXIT_SUCCESS;

}



