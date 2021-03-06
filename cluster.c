#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "MatrixAndVectorOps.h"
#include "modularity.h"
#include "Algorithms.h"
#include "List.h"
#include <time.h>


int main(int argc, char* argv[])
{

	/*-----------------------------------declarations-----------------------------------*/

    char *inFilePath, *outFilePath;
    FILE* outFile;
    int code; /* this integer allows us to catch errors (0 - success, 1- error) */
    int length, degreesSum, i, amountOfGroups, groupSize;
    int* degreesArray;
    int** matrix;
    list** oList;
    list* curr;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    amountOfGroups = 0;


	/*-----------------------------------code-----------------------------------*/

	if (argc != 3){
		printf("ERROR - not enough values to main.");
		return 1;
	}
	inFilePath = argv[1];
    outFilePath = argv[2];

    code = getInputMatrix(inFilePath,&length,&degreesSum,&degreesArray,&matrix);
    if (code == 1){
    	return 1;
    }
    cpu_time_used = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("getInputMatrix : %f seconds\n",cpu_time_used);


    code = Algorithem3(&oList, matrix,length,degreesSum,degreesArray);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("54 : The program took %f seconds\n",cpu_time_used);
    outFile = fopen(outFilePath, "wb");
    for (i = 0; i < length; ++i) {
        if(oList[i] != NULL)
        {
            amountOfGroups++;
        }
    }
    fwrite(&amountOfGroups, sizeof(int),1,outFile);
    printf("%d\n",amountOfGroups);
    for (i = 0; i < amountOfGroups; ++i) {
        curr = oList[i];
        groupSize = ListSize(curr);
        fwrite(&groupSize, sizeof(int),1,outFile);
        printf("Group %d, Size %d\n",i,groupSize);
        printList(curr);
        while (curr)
        {
            fwrite((&curr->val), sizeof(int),1,outFile);
            curr = curr->next;
        }
    }
    free(degreesArray);
    freeIntMatrix(matrix,length);
    for (i = 0; i < length; ++i) {
        freeList(oList[i]);
    }
    free(oList);



    return EXIT_SUCCESS;


}
