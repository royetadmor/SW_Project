/*
 * Created by Roye on 12/08/2020.
 */

#include <stdio.h>
#include <stdlib.h>
#include "spmat.h"
#include "eigen.h"
#include "sparse.h"
#include <assert.h>
#include "MatrixAndVectorOps.h"
/*
 * Power iterations with sparse matrix implementation
 */


/*
 * Calculates Dominant normalized eigenvector using power iterations
 * Input: Matrix, initial vector to start calculation with and matrix size
 * Output: Dominant normalized eigenvector, meaning eigenvector with biggest absolute eigenvalue
 */
double* PowerIterationsWithSparse(double** matrix, double * init_vector, int size)
{
    int iter = 0;
    int i , j;
    double* new_vector;
    spmat* A = spmat_allocate_list(size);
    for (i = 0; i < size; ++i) {
        A->add_row(A,matrix[i],i);
    }
    new_vector = (double*)malloc(size*sizeof(double));
    printVector(size,init_vector);
    while(hasEpsilonDifference(init_vector,new_vector,size) == 0)
    {
        PowerIteration(A,init_vector,new_vector,size);
        iter += 2;
    }
    printf("Iter: %d\n",iter);
    printf("Normalized eigenvector is: \n");
    for (j = 0; j < size; ++j) {
        printf("%f ",init_vector[j]);
    }
    printf("\ndone");
    A->free(A);
    free(new_vector);
    return init_vector;
}

/*
 * 2 Power iterations implementation with sparse matrix
 * Input: Sparse matrix, 2 vectors and matrix size
 * Output: new_vector will contain b_k (from formula in hw1), vector will contain b_k+1
 */
void PowerIteration(spmat* A, double* vector, double* new_vector, int size)
{
    A->mult(A,vector,new_vector);
    normalizeVector(size,new_vector);
    A->mult(A,new_vector,vector);
    normalizeVector(size,vector);
}
