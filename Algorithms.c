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
#include "modularity.h"
#define IS_POSITIVE(x) ((x) > 0.00001)


void Algorithem1(double** modularity_matrix,int length,list* index_list ,list* group1, list* group2)
{
    double* init_vector;
    double eigenvalue;
    double* s_vector;
    double* res_vector;
    double res;
    int i,j;
    list* curr;
    curr = index_list;
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
    Algorithem4(s_vector,modularity_matrix,length);
    multiplyMatrixAndVector(modularity_matrix,s_vector,res_vector,length);
    res = MultiplyVectorAndVector(res_vector,s_vector,length);
    if(!IS_POSITIVE(res))
    {
        return;
    }
    for (j = 0; j < length; ++j) {
        if(IS_POSITIVE(s_vector[j]))
        {
            add(curr->val,group1);
        }
        else
        {
            add(curr->val,group2);
        }
        curr = curr->next;
    }
    free(s_vector);
    free(res_vector);
}


int Algorithem3(list*** oListToReturn ,int** input_matrix,int length,int degreesSum, int*degreesArray)
{
    int i, pIndex, oIndex; /* j, */
    list* index_list;
    list** pList;
    list** oList;
    list* group1;
    list* group2;
    double** modMatrix;
    double **BTagMatrix;
    pIndex = 0;
    oIndex = 0;
    pList = (list**)malloc(length* sizeof(list*));
    oList = (list**)malloc(length* sizeof(list*));
    index_list = init_list();
    for (i = 0; i < length; ++i) {
        add(i,index_list);
    }
    pList[pIndex] = index_list;
    ++pIndex;
    while (pIndex != 0)
    {
        group1 = init_list();
        group2 = init_list();
        getModularityMatrix(&modMatrix,length,degreesSum,degreesArray,input_matrix);
        getBTagMatrix(&BTagMatrix, length, modMatrix,pList[pIndex - 1]);

        /* printf("\n\nThe Vector:\n");
        printList(pList[pIndex - 1]);
        printf("BTagMatrix:\n");
        printDoubleMat(BTagMatrix, ListSize(pList[pIndex - 1]));
        printf("\n");*/

        Algorithem1(BTagMatrix,ListSize(pList[pIndex - 1]),pList[pIndex - 1],group1,group2);
        if(ListSize(group1) == 0 || ListSize(group2) == 0)
        {
            oList[oIndex] = pList[pIndex - 1];
            oIndex++;
            pList[pIndex - 1] = NULL;
            --pIndex;
        }
        else
        {
            pList[pIndex - 1] = NULL;
            --pIndex;
            if (ListSize(group1) == 1)
            {
                oList[oIndex] = group1;
                oIndex++;
            } else
            {
                pList[pIndex] = group1;
                pIndex++;
            }
            if (ListSize(group2) == 1)
            {
                oList[oIndex] = group2;
                oIndex++;
            } else
            {
                pList[pIndex] = group2;
                pIndex++;
            }

        }
        /* printf("pList:\n");
        for (j = 0; j < pIndex; ++j) {
            printList(pList[j]);
        }
        printf("oList:\n");
        for (j = 0; j < oIndex; ++j) {
            printList(oList[j]);
        } */
    }
    freeList(index_list);
    freeList(group1);
    freeList(group2);
    /* printf("Done\n"); */
    *oListToReturn = oList;
    return 0;

}



void Algorithem4(double* s_vector, double** modularity_matrix, int length)
{
    /* Declarations */
    double delta_q,tmp;
    int i,j,k, tmp_int;
    double* res;
    double* score;
    int* indices;
    double* improvement;
    int i_tag;
    int j_tag;
    list* unmoved;
    list* curr;
    delta_q = 1.0;
    i_tag = -1;
    j_tag = -1;
    res = (double*)malloc(length* sizeof(double));
    score = (double*)malloc(length* sizeof(double));
    indices = (int*)malloc(length* sizeof(int));
    improvement = (double*)malloc(length*sizeof(double));
    /* Declarations */


    while (IS_POSITIVE(delta_q))
    {
        /* Creating set of unmoved indices */
        unmoved = init_list();
        for (i = 0; i < length; ++i) {
            add(i,unmoved);
        }
        curr = unmoved;

        /* Looking for improvement for the partition */
        for (i = 0; i < length; ++i) {

            /* Calculating score for each vertex and finding maximum score's index */
            multiplyMatrixAndVector(modularity_matrix,s_vector,res,length);
            while (curr)
            {
                score[curr->val] = -4*s_vector[curr->val] * res[curr->val] + 4*modularity_matrix[curr->val][curr->val];
                curr = curr->next;
            }
            curr = unmoved;
            tmp = -DBL_MAX;
            while (curr)
            {
                if(score[curr->val] > tmp)
                {
                    tmp = score[curr->val];
                    j_tag = curr->val;
                }
                curr = curr->next;
            }

            /* moving vertex j_tag and calculating improvement */
            s_vector[j_tag] = (-1)*s_vector[j_tag];
            indices[i] = j_tag;
            if(i == 0)
            {
                improvement[i] = score[j_tag];
            } else
            {
                improvement[i] = improvement[i-1] + score[j_tag];
            }

            /* Remove and reset */
            unmoved = removeNode(j_tag,unmoved);
            curr = unmoved;
        }

        /* Calculating best improvement for s and update accordingly */
        tmp = -DBL_MAX;
        for (j = 0; j < length; ++j) {
            if (tmp < improvement[j])
            {
                i_tag = j;
                tmp = improvement[j];
            }
        }
        for (k = length - 1; k > i_tag ; --k) {
            tmp_int = indices[k];
            s_vector[tmp_int] = (-1)*s_vector[tmp_int];

        }
        if (i_tag == length)
        {
            delta_q = 0;
        } else{
            delta_q = improvement[i_tag];
        }
        /* printf("Improvement delta: %f\n",delta_q); */
    }
    free(res);
    free(score);
    free(indices);
    free(improvement);
    freeList(curr);
    freeList(unmoved);

}
