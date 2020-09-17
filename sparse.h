#ifndef SW_PROJECT_SPARSE_H
#define SW_PROJECT_SPARSE_H

#include "spmat.h"
double* PowerIterationsWithSparse(double** matrix, double * init_vector, int size);
void PowerIteration(spmat* A, double* vector, double* new_vector, int size);
#endif /*SW_PROJECT_SPARSE_H*/
