//
// Created by Roye on 12/08/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "spmat.h"
#include "eigen.h"
#define SIZE 5


double* PowerIterationsWithSparse(double** matrix, double * init_vector, int size);
void PowerIteration(spmat* A, double* vector, double* new_vector, int size);
int main()
{
    double ** arr = (double**)malloc(SIZE*sizeof(double*));
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = (double*)malloc(SIZE* sizeof(double));
    }
    for (int j = 0; j < SIZE; ++j) {
        for (int k = 0; k < SIZE; ++k) {
            arr[j][k] = j+k;
        }
    }
    double *vec = (double*)malloc(SIZE* sizeof(double));
    for (int l = 0; l < SIZE; ++l) {
        vec[l] = 1;
    }
    PowerIterationsWithSparse(arr,vec,SIZE);
    free(arr);
}

double* PowerIterationsWithSparse(double** matrix, double * init_vector, int size)
{
    spmat* A = spmat_allocate_list(size);
    for (int i = 0; i < size; ++i) {
        A->add_row(A,matrix[i],i);
    }
    double* new_vector = (double*)calloc(size,sizeof(double));
    PowerIteration(A,init_vector,new_vector,size);

    while(hasEpsilonDifference(new_vector,init_vector,size) == 0)
    {
        PowerIteration(A,init_vector,new_vector,size);
    }
    printf("Normalized eigenvector is: \n");
    for (int j = 0; j < SIZE; ++j) {
        printf("%f ",init_vector[j]);
    }
    printf("\ndone");
    A->free(A);
    return init_vector;
}

void PowerIteration(spmat* A, double* vector, double* new_vector, int size)
{
    A->mult(A,vector,new_vector);
    normalizeVector(size,new_vector);
    A->mult(A,new_vector,vector);
    normalizeVector(size,vector);
}