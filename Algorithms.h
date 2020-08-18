//
// Created by Roye on 18/08/2020.
//

#ifndef SW_PROJECT_ALGORITHMS_H
#define SW_PROJECT_ALGORITHMS_H
typedef struct division
{
    int length_of_group1;
    int length_of_group2;
    int* group1;
    int* group2;
}division;
division* Algorithem1(double** modularity_matrix,int length);
#endif //SW_PROJECT_ALGORITHMS_H
