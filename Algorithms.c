/*
* Created by Roye on 18/08/2020.
*/

#include "Algorithms.h"
#include "MatrixAndVectorOps.h"
#include <stdlib.h>
#include <stdio.h>
#include "MathHelpers.h"
#include "List.h"
#include "math.h"
#include "float.h"
#define IS_POSITIVE(x) ((x) > 0.00001)
#define MAX(x,y)((x)>(y)?x:y)


void Algorithem1(double** modularity_matrix,int length, list* group1, list* group2)
{
    double* init_vector;
    double eigenvalue;
    double* s_vector;
    double* res_vector;
    double res;
    int i,j;
    s_vector = (double*)malloc(length* sizeof(double));
    res_vector = (double*)malloc(length* sizeof(double));
    init_vector = generateRandomVector(length);
    eigenvalue = CalculateLeadingEigenpair(modularity_matrix,init_vector,length);
    if(!IS_POSITIVE(eigenvalue))
    {
        return;
    }
    for (i = 0; i < length; ++i)
    {
        if(IS_POSITIVE(init_vector[i]))
        {
            s_vector[i] = 1;
        }
        else
        {
            s_vector[i] = -1;
        }
    }
    multiplyMatrixAndVector(modularity_matrix,s_vector,res_vector,length);
    res = MultiplyVectorAndVector(res_vector,s_vector,length);
    if(!IS_POSITIVE(res))
    {
        return;
    }
    for (j = 0; j < length; ++j) {
        if(IS_POSITIVE(s_vector[j]))
        {
            add(j,group1);
        }
        else
        {
            add(j,group2);
        }
    }
    free(s_vector);

}

/*
 void algorithem4(double* s_vector, double** modularity_matrix, int length)
{
    double delta_q;
    int i,q,tmp;
    double* res;
    int* score;
    int* indices;
    int* improvement;
    int i_tag;
    int j_tag;
    list* unmoved;
    list* curr;
    delta_q = 1;
    j_tag = (int)-DBL_MAX;
    j_tag = -DBL_MAX;
    unmoved = init_list();
    curr = unmoved;
    res = (double*)malloc(length* sizeof(double));
    score = (int*)malloc(length* sizeof(int));
    indices = (int*)malloc(length* sizeof(int));
    improvement = (int*)malloc(length* sizeof(int));

    for (i = 0; i < length; ++i) {
        add(i,unmoved);
    }
    while (IS_POSITIVE(delta_q))
    {
        for (i = 0; i < length; ++i) {
            multiplyMatrixAndVector(modularity_matrix,s_vector,res,length);
            q = MultiplyVectorAndVector(s_vector,res,length);
            while (curr)
            {
                s_vector[curr->val] = (-1)*s_vector[curr->val];
                multiplyMatrixAndVector(modularity_matrix,s_vector,res,length);
                tmp = MultiplyVectorAndVector(s_vector,res,length);
                score[curr->val] = q - tmp;
                s_vector[curr->val] = (-1)*s_vector[curr->val];
                curr = curr->next;
            }
            curr = unmoved;
            while (curr)
            {
                j_tag = (j_tag,score[curr->val]);
                curr = curr->next;
            }
            s_vector[j_tag] = (-1)*s_vector[j_tag];
            indices[i] = j_tag;
            if(i == 0)
            {
                improvement[i] = score[j_tag];
            } else
            {
                improvement[i] = improvement[i-1] + score[j_tag];
            }
            removeNode(j_tag,unmoved);
        }



    }
}
*/
