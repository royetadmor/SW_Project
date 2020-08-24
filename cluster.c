/*
 * Created by Roye on 18/08/2020.
 */


#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "MatrixAndVectorOps.h"
#include "modularity.h"
#include "Algorithms.h"


int main(int argc, char* argv[])
{
    char* file;
    int length, degreesSum;
    int* degreesArray;
    int** matrix;
    double** modMatrix;
    division* division1;
    printf("Because gcc is annoying: %d\n",argc);
    file = argv[1];
    file = "/Users/user/CLionProjects/SW_Project/graph.in";
    getInputMatrix(file,&length,&degreesSum,&degreesArray,&matrix);
    getModularityMatrix(&modMatrix,length,degreesSum,degreesArray,matrix);
    printDoubleMat(modMatrix,length);
    division1 = Algorithem1(modMatrix,length);
    printVector(division1->length_of_group1,(double*)division1->group1);
    printf("Done");


}
