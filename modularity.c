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

/* include internal packages */
#include "input.c"


int getMultMatrix(int*** multMatrix, int length, int* array){

	int **myMultMatrix = (int**)calloc(length, sizeof(int*));
	int i = 0 , j = 0;

	for(; i< length; i++){
		myMultMatrix[i] = (int*)calloc(length, sizeof(int));
		for (; j < length; j++){
			myMultMatrix[i][j] = array[i] * array[j];
		}
		myMultMatrix[i][i] = 0;
	}

	*multMatrix = myMultMatrix;

	return EXIT_SUCCESS;
}


int main(int argc, char* argv[]) {


	/*-----------------------------------declarations-----------------------------------*/


	int **matrix = NULL;
	int *degreesArray = NULL;
	int degreesSum;
	int length;
	int ass;
	int i = 0 ,j = 0;

	/*-----------------------------------code-----------------------------------*/


	DEBUG_PRINT(("Validating input existence ... \n"));

	assert(argc != 0);
	assert(argv[1] != NULL);

	DEBUG_PRINT(("There is input.\n"));


	DEBUG_PRINT(("Validating input existence ... \n"));
	ass = getInputMatrix(argv[1], &length, &degreesSum, &degreesArray, &matrix);
	for (; i < length; i ++){
		for(; j < length; j++){
			printf("%d ",*(*(matrix + i)+j) );
		}
		printf("\n");
	}
	assert(ass == 0);







	return EXIT_SUCCESS;

}
