/*
 * Created by Roye on 18/08/2020.
 */

#ifndef SW_PROJECT_MATHHELPERS_H
#define SW_PROJECT_MATHHELPERS_H

/*
 * Module for computing eigenvalue and leading eigenpair
 */

/*
 * Calculates the eigenvalue of a given vector based on formula.
 * Eigenvalue returns as a double
 */
double CalculateEigenvalue(double** matrix, double* vector, int length);


/*
 * Calculates the 1-norm of a given matrix.
 * Used for the matrix shifting
 */
double Calculate1norm(double** matrix,int length);

/*
 * Calculates the matrix after adding the 1-norm (C' = ||C_1||*I + C)
 */
void CalculateNewMatrix(double** matrix, double norm ,int length);

/*
 * Calculates the leading eigenpair using sparse impl.
 * NOTE: since we are required for computing the leading eigenpair, we are doing the following:
 *  - init_vector will contain the leading eigenvctor after the function was called.
 *  - The eigenvalue is the return value of the function.
 */
double CalculateLeadingEigenpair(double** matrix,double* init_vector, int length);

#endif /*SW_PROJECT_MATHHELPERS_H*/
