//
// Created by Roye on 18/08/2020.
//

#include "Algorithms.h"
#include "MatrixAndVectorOps.h"
#include <stdlib.h>
#include <stdio.h>
#include "MathHelpers.h"
#define IS_POSITIVE(x) ((x) > 0.00001)


division* Algorithem1(double** modularity_matrix,int length)
{
    double* init_vector;
    double eigenvalue;
    double* s_vector = (double*)malloc(length* sizeof(double));
    double* res_vector;
    double res;
    int length_of_group1;
    int length_of_group2;
    int temp_length1 = 0;
    int temp_length2 = 0;
    division* division1 = (division*)malloc(sizeof(division));
    init_vector = generateRandomVector(length);
    eigenvalue = CalculateLeadingEigenpair(modularity_matrix,init_vector,length);
    if(!IS_POSITIVE(eigenvalue))
    {
        return NULL;
    }
    for (int i = 0; i < length; ++i)
    {
        if(IS_POSITIVE(init_vector[i]))
        {
            s_vector[i] = 1;
            ++length_of_group1;
        }
        else
        {
            s_vector[i] = -1;
            ++length_of_group2;
        }
    }
    multiplyMatrixAndVector(modularity_matrix,s_vector,res_vector,length);
    res = MultiplyVectorAndVector(res_vector,s_vector,length);
    if(!IS_POSITIVE(res))
    {
        return NULL;
    }
    division1->group1 = (int*)malloc(length_of_group1* sizeof(int));
    division1->group2 = (int*)malloc(length_of_group2* sizeof(int));
    division1->length_of_group1 = length_of_group1;
    division1->length_of_group2 = length_of_group2;
    for (int j = 0; j < length; ++j) {
        if(IS_POSITIVE(s_vector[j]))
        {
            division1->group1[temp_length1] = j;
            ++temp_length1;
        }
        else
        {
            division1->group2[temp_length2] = j;
            ++temp_length2;
        }
    }
    free(s_vector);
    return division1;

}