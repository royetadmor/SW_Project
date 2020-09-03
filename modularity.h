/*
 * modularity.h
 *
 *  Created on: 18 Aug 2020
 *      Author: hadar
 */
#include "List.h"


#ifndef MODULARITY_H_
#define MODULARITY_H_


int getModularityMatrix(double ***modMatrix, int length, int degreesSum, int* degreesArray, int**matrix);
int getBTagMatrix(double ***BTagMatrix, double **modMatrix, list *indices);


#endif /* MODULARITY_H_ */
