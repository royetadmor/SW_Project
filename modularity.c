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
 /*
int generateBTagMatrix(list *head, double ***BTagMatrix, double **modularityMatrix){

	int myBTagMatrixLength;
	double **myBTagMatrix ;

	myBTagMatrixLength = ListSize(head);
	myBTagMatrix = (double**)calloc(myBTagMatrixLength, sizeof(double*));

	printDoubleMat(*myBTagMatrix, myBTagMatrixLength);


	return EXIT_SUCCESS;

}

*/

