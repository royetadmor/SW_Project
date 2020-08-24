/*
* Created by Roye on 18/08/2020.
*/

#include "Algorithms.h"
#include "MatrixAndVectorOps.h"
#include <stdlib.h>
#include <stdio.h>
#include "MathHelpers.h"
#include "List.h"
#define IS_POSITIVE(x) ((x) > 0.00001)


void Algorithem1(double** modularity_matrix,int length, list* group1, list* group2)
{
    double* init_vector;
    double eigenvalue;
    double* s_vector;
    double* res_vector;
    double res;
    int i,j;
    s_vector = (double*)malloc(length* sizeof(double));
    res_vector = (double*)malloc(length* sizeof(double));
    init_vector = generateRandomVector(length);
    eigenvalue = CalculateLeadingEigenpair(modularity_matrix,init_vector,length);
    if(!IS_POSITIVE(eigenvalue))
    {
        return;
    }
    for (i = 0; i < length; ++i)
    {
        if(IS_POSITIVE(init_vector[i]))
        {
            s_vector[i] = 1;
        }
        else
        {
            s_vector[i] = -1;
        }
    }
    multiplyMatrixAndVector(modularity_matrix,s_vector,res_vector,length);
    res = MultiplyVectorAndVector(res_vector,s_vector,length);
    if(!IS_POSITIVE(res))
    {
        return;
    }
    for (j = 0; j < length; ++j) {
        if(IS_POSITIVE(s_vector[j]))
        {
            add(j,group1);
        }
        else
        {
            add(j,group2);
        }
    }
    free(s_vector);

}



