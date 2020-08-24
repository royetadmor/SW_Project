/*
 * Created by Roye on 18/08/2020.
 */


#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "MatrixAndVectorOps.h"


int main(int argc, char* argv[])
{
    char* file;
    int length, degreesSum;
    int* degreesArray;
    int** matrixPointer;
    printf("Because ggc is annoying: %d\n",argc);
    file = argv[1];
    getInputMatrix(file,&length,&degreesSum,&degreesArray,&matrixPointer);

}
