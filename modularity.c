/* include system packages */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "List.h"
#include "MatrixAndVectorOps.h"



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


int getBTagMatrix(double ***BTagMatrix, int length, double **modMatrix, list *indices){

	int indicesLength;
    double **myBTagMatrix;
    double tmpVal, nodeSum;
    int i, j;
    list *rowPointer, *columnsPointer;


    indicesLength = ListSize(indices);
    myBTagMatrix = (double**)calloc(indicesLength, sizeof(double*));
	rowPointer = indices;
    for(i = 0 ; i < indicesLength; i++){
    	nodeSum = 0;
    	columnsPointer = indices;
    	myBTagMatrix[i] = (double*)calloc(indicesLength, sizeof(double));
    	for(j = 0; j < indicesLength ; j++){
    		tmpVal = modMatrix[rowPointer->val][columnsPointer->val];
    		myBTagMatrix[i][j] = tmpVal;
    		nodeSum += tmpVal;
    		columnsPointer = columnsPointer->next;
    	}
    	/* printf("%d", length); */
    	nodeSum = 0;
    	for(j = 0; j < length; j++ ){
    		nodeSum += modMatrix[i][j];
    	}
		myBTagMatrix[i][i] -= nodeSum;
    	rowPointer = rowPointer->next;
    }

    *BTagMatrix = myBTagMatrix;

	return EXIT_SUCCESS;
}


