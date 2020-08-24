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




int getModularityMatrix(double ***multMatrix, int length, int degreesSum, int* degreesArray, int**matrix){
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

	*multMatrix = myMultMatrix;
	return EXIT_SUCCESS;
}



/*

int main(int argc, char* argv[]) {


	/ *-----------------------------------declarations-----------------------------------* /


	int **matrix = NULL;
	double **multMatrix = NULL;
	int *degreesArray = NULL;
	int degreesSum;
	int length;
	int ass;

	/ *-----------------------------------code-----------------------------------* /

	DEBUG_PRINT(("Validating input existence ... \n"));

	assert(argc != 0);
	assert(argv[1] != NULL);

	DEBUG_PRINT(("There is input.\n"));


	DEBUG_PRINT(("Validating input existence ... \n"));
	ass = getInputMatrix(argv[1], &length, &degreesSum, &degreesArray, &matrix);
	assert(ass == 0);

	ass = getMultMatrix(&multMatrix, length, degreesSum , degreesArray, matrix);


	assert(ass == 0);


	return EXIT_SUCCESS;

}

 */

