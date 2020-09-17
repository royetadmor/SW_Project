#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "MatrixAndVectorOps.h"


int createCovMatrix(double **covMatrix ,double **matrix, int numberOfRows, int numberOfColumns){
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
	return EXIT_SUCCESS;
}


int printMatrixToFile(int numberOfRows,int numberOfColumns,double **matrix, FILE *file){

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

	return EXIT_SUCCESS;

}

