/*
 * input.c
 *
 *  Created on: 12 Aug 2020
 *      Author: hadar
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>



#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

int main(int argc, char* argv[]) {


	/* the 1st argument (input filename) is in argv[0]  */


	/*-----------------------------------declarations-----------------------------------*/


	char *inFile;
	FILE *file ;
	int numOfNodes;
	int ass = 0; /* this variable is being set to 1 in order to assert if needed */
	int **matrix; /* this is the matrix which we generate from the input file  */
	int i, j, q; /* those variables are being used to iterate */
	int nodeDegree;
	int neighborIndex;

	/*-----------------------------------code-----------------------------------*/


	DEBUG_PRINT(("Validating input file... \n"));

	assert(argc == 0 || argc != 0);
	assert(argv[1] != NULL);
	inFile = argv[1];
	file = fopen(inFile, "r");
	assert(file!=NULL);

	DEBUG_PRINT(("The input is valid.\n"));


	/*-----------------------------------*/


	DEBUG_PRINT(("Start - Creating the matrix... \n"));

	ass = fread(&numOfNodes, sizeof(int), 1, file);
	assert(ass == 1);

	DEBUG_PRINT(("numOfNodes: %d\n", numOfNodes));

	matrix = (int**)calloc(numOfNodes, sizeof(int*));

	/* The following code can be optimized by keeping the next neighbor - it will lead to insert value to each node only once (now can be twice if neighbors).
	 * another optimization can be done with the face the the matrix is symmetric.  */

	for(i = 0 ; i < numOfNodes ; i++){ /* i represents the i_th node */

		matrix[i] = (int*)calloc(numOfNodes, sizeof(int));

		for(j = 0 ; j < numOfNodes; j++){ /* filling 0's as a default value - as the nodes were not neighbors */

			matrix[i][j] = 0;

		}

		ass = fread(&nodeDegree, sizeof(int), 1, file);
		assert(ass == 1);
		DEBUG_PRINT(("%d_th node : degree is %d.\n it's neighbors are: ", i, nodeDegree));

		for (q = 0; q < nodeDegree; q++){
			ass = fread(&neighborIndex, sizeof(int), 1, file);
			assert(ass == 1);
			DEBUG_PRINT(("%d ", neighborIndex));
			matrix[i][neighborIndex] = 1;
		}

		DEBUG_PRINT((" .\n"));

	}

	/*free(neighborNodes);*/

	DEBUG_PRINT(("End - Creating the matrix. \n"));

	for (i = 0 ; i < numOfNodes ; i ++){
		for(j = 0 ; j < numOfNodes; j++){
			printf("%d ",*(*(matrix + i)+j) );
		}
		printf("\n");
	}



	/*-----------------------------------*/


	return EXIT_SUCCESS;

}



