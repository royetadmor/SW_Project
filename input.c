#include <stdio.h>
#include <assert.h>
#include <stdlib.h>




/**
 * The method assign length and matrix to the corresponding pointers.
 * return 0 if the process succeed.
 */
int getInputMatrix(char* binaryInput, int *lengthPointer, int* degreesSum, int** degreesArray, int***matrixPointer) {


	/*-----------------------------------declarations-----------------------------------*/

	FILE *file ;
	int numOfNodes;
	int ass = 0; /* this variable is being set to 1 in order to assert if needed */
	int **matrix; /* this is the matrix which we generate from the input file  */
	int* myDegreesArray;
	int i, j, q; /* those variables are being used to iterate */
	int nodeDegree;
	int neighborIndex;
	int myDegreesSum = 0;

	/*-----------------------------------code-----------------------------------*/


	if(lengthPointer == 0){};
	if(matrixPointer == 0){};
	if(degreesSum == 0){};
	if(degreesArray == 0){};

	/* "Validating input file. */

	assert(binaryInput != 0);
	assert(binaryInput != NULL);
	file = fopen(binaryInput, "r");
	assert(file!=NULL);

	/* "The input is valid. */


	/*-----------------------------------*/


	/* "Start - Creating the matrix... \n" */

	ass = fread(&numOfNodes, sizeof(int), 1, file);
	assert(ass == 1);

	matrix = (int**)calloc(numOfNodes, sizeof(int*));

	myDegreesArray = (int*)calloc(numOfNodes, sizeof(int));

	/* The following code can be optimized by keeping the next neighbor - it will lead to insert value to each node only once (now can be twice if neighbors).
	 * another optimization can be done with the face the the matrix is symmetric.  */

	for(i = 0 ; i < numOfNodes ; i++){ /* i represents the i_th node */

		matrix[i] = (int*)calloc(numOfNodes, sizeof(int));

		for(j = 0 ; j < numOfNodes; j++){ /* filling 0's as a default value - as the nodes were not neighbors */

			matrix[i][j] = 0;

		}

		ass = fread(&nodeDegree, sizeof(int), 1, file);
		assert(ass == 1);
		myDegreesSum += nodeDegree;
		myDegreesArray[i] = nodeDegree;

		for (q = 0; q < nodeDegree; q++){
			ass = fread(&neighborIndex, sizeof(int), 1, file);
			assert(ass == 1);
			matrix[i][neighborIndex] = 1;
		}

	}

	/*free(neighborNodes);*/

	/* "End - Creating the matrix. */


	/*-----------------------------------*/

	*matrixPointer = matrix;
	*degreesArray = myDegreesArray;
	*lengthPointer = numOfNodes;
	*degreesSum = myDegreesSum;
	return EXIT_SUCCESS;

}




