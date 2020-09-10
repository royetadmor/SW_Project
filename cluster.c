/*
 * Created by Roye on 18/08/2020.
 */


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
    char *inFilePath, *outFilePath;
    FILE* outFile;
    int length, degreesSum, i, amountOfGroups, groupSize;
    int* degreesArray;
    int** matrix;
    list** oList;
    list* curr;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    amountOfGroups = 0;
    printf("Because gcc is annoying: %d\n",argc);
    inFilePath = argv[1];
    outFilePath = argv[2];
    /* inFilePath = "/Users/user/CLionProjects/SW_Project/graph.in"; */
    getInputMatrix(inFilePath,&length,&degreesSum,&degreesArray,&matrix);
    oList = Algorithem3(matrix,length,degreesSum,degreesArray);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The program took %f seconds\n",cpu_time_used);
    outFile = fopen(outFilePath,"wb");
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



    return EXIT_SUCCESS;


}
