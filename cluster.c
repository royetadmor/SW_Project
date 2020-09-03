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


int main(int argc, char* argv[])
{
    char* file;
    int length, degreesSum;
    int* degreesArray;
    int** matrix;
    printf("Because gcc is annoying: %d\n",argc);
    file = argv[1];
    getInputMatrix(file,&length,&degreesSum,&degreesArray,&matrix);
    Algorithem3(matrix,length,degreesSum,degreesArray);


    return EXIT_SUCCESS;


}
