/*
 * Created by Roye on 18/08/2020.
 */

#include "MathHelpers.h"
#include "MatrixAndVectorOps.h"
#include <stdlib.h>
#include "eigen.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include "sparse.h"



double CalculateEigenvalue(double** matrix, double* vector, int length)
{
    double* vec;
    double upper,lower;
    vec = (double*)malloc(length* sizeof(double));
    multiplyMatrixAndVector(matrix,vector,vec,length);
    upper = MultiplyVectorAndVector(vec,vector,length);
    lower = MultiplyVectorAndVector(vector,vector,length);
    free(vec);
    return (upper/lower);

}

double CalculateLeadingEigenpair(double** matrix,double* init_vector, int length)
{
    double norm1;
    double eigen_val;
    /*double **tag_matrix;
    int i,j,k;*/
    /*
    tag_matrix = (double**)malloc(length* sizeof(double*));
    for (i = 0; i < length; ++i) {
        tag_matrix[i] = (double*)malloc(length* sizeof(double));
    }
    for (i = 0; i < length; ++i) {
        for (j = 0; j < length; ++j) {
            tag_matrix[i][j] = matrix[i][j];
        }
    }
     */
    norm1 = Calculate1norm(matrix,length);
    CalculateNewMatrix(matrix,norm1,length);
    PowerIterationsWithSparse(matrix,init_vector,length);
    eigen_val = CalculateEigenvalue(matrix,init_vector,length);
    eigen_val = eigen_val - norm1;
    CalculateNewMatrix(matrix,-norm1,length);
    /*
    for (k = 0; k < length; ++k) {
        free(tag_matrix[k]);
    }
    free(tag_matrix);
     */
    return eigen_val;


}


double Calculate1norm(double** matrix,int length)
{
    double* arr;
    double max;
    int i, j, k;
    max = -DBL_MAX;
    arr = (double*)malloc(length* sizeof(double));
    for (i = 0; i < length; ++i) {
        for (j = 0; j < length; ++j) {
            arr[j] += fabs(matrix[i][j]);
        }
    }
    for (k = 0; k < length; ++k) {
    	if(arr[k] > max){
            max = arr[k];
    	}
    }
    free(arr);
    return max;
}
void CalculateNewMatrix(double** matrix, double norm ,int length)
{
    int i;
    for (i = 0; i < length; ++i) {
        matrix[i][i] += norm;
    }
}
