//
// Created by Roye on 18/08/2020.
//

#include "MathHelpers.h"
#include "MatrixAndVectorOps.h"
#include <stdlib.h>
#include "eigen.h"
#include <stdio.h>
#include <math.h>
#include <float.h>




double CalculateEigenvalue(double** matrix, double* vector, int length)
{
    double* vec = (double*)malloc(length* sizeof(double));
    multiplyMatrixAndVector(matrix,vector,vec,length);
    double upper = MultiplyVectorAndVector(vec,vector,length);
    double lower = MultiplyVectorAndVector(vector,vector,length);
    free(vec);
    return (upper/lower);

}

double CalculateLeadingEigenpair(double** matrix,double* init_vector, int length)
{
    double norm1 = Calculate1norm(matrix,length);
    double* new_vector = (double*)calloc(length, sizeof(double));
    CalculateNewMatrix(matrix,norm1,length);
    while (hasEpsilonDifference(init_vector,new_vector,length) == 0)
    {
        iterate(matrix,init_vector,new_vector,length);
    }
    free(new_vector);
    double eigen_val = CalculateEigenvalue(matrix,init_vector,length);
    eigen_val = eigen_val - norm1;
    return eigen_val;


}


double Calculate1norm(double** matrix,int length)
{
    double* arr = (double*)malloc(length* sizeof(double));
    double max = -DBL_MAX;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            arr[j] += fabs(matrix[i][j]);
        }
    }
    for (int k = 0; k < length; ++k) {
        max = fmax(max,arr[k]);
    }
    free(arr);
    return max;
}
void CalculateNewMatrix(double** matrix, int norm ,int length)
{
    for (int i = 0; i < length; ++i) {
        matrix[i][i] += norm;
    }
}
