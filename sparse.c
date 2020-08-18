//
// Created by Roye on 12/08/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "spmat.h"
#include "eigen.h"
#include "sparse.h"
#include <assert.h>
/*
 * Power iterations with sparse matrix implementation
 */

//int main()
//{
//    FILE* file;
//    int size = 0;
//    int num;
//    double hamin;
//    file = fopen("/Users/user/CLionProjects/SW_Project/input.arr","r");
//    fread(&size,sizeof(int),1,file);
//    fread(&num,sizeof(int),1,file);
//    printf("%d\n",size);
//    printf("%d\n",num);
//    spmat* A = spmat_allocate_list(size);
//    double* row = (double*)malloc(size * sizeof(double));
//    for (int i = 0; i < size; ++i) {
//        for (int k = 0; k < size; ++k) {
//            fread(&row[k], sizeof(double),1,file);
//        }
//        printVector(size,row);
//        A->add_row(A,row,i);
//    }
//    double* init = (double*)malloc(size* sizeof(double));
//    for (int j = 0; j < size; ++j) {
//        init[j] = 1;
//    }
//    double* result = PowerIterationsWithSparse(A,init,size);
//    file = fopen("/Users/user/CLionProjects/SW_Project/eigen.out", "w+");
//	assert(file!=NULL);
//	printVectorToFile(size,result,file);
//	fclose(file);
//
//}

/*
 * Calculates Dominant normalized eigenvector using power iterations
 * Input: Matrix, initial vector to start calculation with and matrix size
 * Output: Dominant normalized eigenvector, meaning eigenvector with biggest absolute eigenvalue
 */
double* PowerIterationsWithSparse(spmat *matrix, double * init_vector, int size)
{
    int iter = 0;
    spmat* A = matrix;
//    for (int i = 0; i < size; ++i) {
//        A->add_row(A,matrix[i],i);
//    }
    double* new_vector = (double*)malloc(size*sizeof(double));
    printVector(size,init_vector);
    while(hasEpsilonDifference(init_vector,new_vector,size) == 0)
    {
        PowerIteration(A,init_vector,new_vector,size);
        iter += 2;
    }
    printf("Normalized eigenvector is: \n");
    printf("Iter: %d\n",iter);
    for (int j = 0; j < size; ++j) {
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
