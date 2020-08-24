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
    double** modMatrix;
    list* group1;
    list* group2;
    group1 = init_list();
    group2 = init_list();
    printf("Because gcc is annoying: %d\n",argc);
    file = argv[1];
    /*file = "/Users/user/CLionProjects/SW_Project/graph.in";*/
    getInputMatrix(file,&length,&degreesSum,&degreesArray,&matrix);
    getModularityMatrix(&modMatrix,length,degreesSum,degreesArray,matrix);
    printDoubleMat(modMatrix,length);
    Algorithem1(modMatrix,length,group1,group2);
    printList(group1);
    printList(group2);
    printf("Done");


}
