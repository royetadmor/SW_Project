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
#include <time.h>
#define IS_POSITIVE(x) ((x) > 0.00001)


void Algorithem1(double** modularity_matrix,int length,list* index_list ,list* group1, list* group2)
{
	clock_t start;
    double* init_vector;
    double eigenvalue;
    double* s_vector;
    double* res_vector;
    double res;
    int i,j;
    double iter_time;
    list* curr;

    start = clock();
    curr = index_list;
    s_vector = (double*)malloc(length* sizeof(double));
    res_vector = (double*)malloc(length* sizeof(double));
    init_vector = generateRandomVector(length);
    iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("init_vector : %f seconds\n", iter_time);

    start = clock();
    eigenvalue = CalculateLeadingEigenpair(modularity_matrix,init_vector,length);
    iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("eigenvalue : %f seconds\n", iter_time);


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
    start = clock();
    Algorithem4(s_vector,modularity_matrix,length);
    iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("Algorithem4 : %f seconds\n", iter_time);
    start = clock();
    multiplyMatrixAndVector(modularity_matrix,s_vector,res_vector,length);
    iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;


    start = clock();
    res = MultiplyVectorAndVector(res_vector,s_vector,length);
    iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;

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
    free(init_vector);
}


int Algorithem3(list*** oListToReturn ,int** input_matrix,int length,int degreesSum, int*degreesArray)
{
	clock_t start;
    int i, pIndex, oIndex, list_size;
    list* index_list;
    list** pList;
    list** oList;
    list* group1;
    list* group2;
    double **modMatrix;
    double **BTagMatrix;
    double iter_time;
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
    getModularityMatrix(&modMatrix,length,degreesSum,degreesArray,input_matrix);
    while (pIndex != 0)
    {
        group1 = init_list();
        group2 = init_list();
        list_size = ListSize(pList[pIndex - 1]);
        getBTagMatrix(&BTagMatrix, length, modMatrix,pList[pIndex - 1]);
        start = clock();
        Algorithem1(BTagMatrix,list_size,pList[pIndex - 1],group1,group2);
        iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        printf("Algorithem1 : %f seconds\n", iter_time);
        if(ListSize(group1) == 0 || ListSize(group2) == 0)
        {
            oList[oIndex] = pList[pIndex - 1];
            oIndex++;
            pList[pIndex - 1] = NULL;
            --pIndex;
            freeList(group1);
            freeList(group2);
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
        iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
        printf("pIndex != 0 Iteration : %f seconds\n", iter_time);
        freeDoubleMatrix(BTagMatrix,list_size);

    }
    for (i = 0; i< length; ++i) {
            freeList(pList[i]);
    }
    free(pList);
    freeList(index_list);

    freeDoubleMatrix(modMatrix,length);
    *oListToReturn = oList;
    return 0;

}



void Algorithem4(double* s_vector, double** modularity_matrix, int length)
{
    /* Declarations */
    double delta_q,tmp;
    int i,j,k,l, tmp_int;
    double* res;
    double* score;
    int* indices;
    double* improvement;
    int i_tag;
    int j_tag;
    double iter_time;
    clock_t start;
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
        multiplyMatrixAndVector(modularity_matrix,s_vector,res,length);
        printf("Starting first for\n");
        j_tag = -1;
        for (i = 0; i < length; ++i) {

            /* Calculating score for each vertex and finding maximum score's index */
            start = clock();
            /*multiplyMatrixAndVector(modularity_matrix,s_vector,res,length);*/
            iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            if (j_tag != -1)
            {
                for (l = 0; l < length; ++l) {
                    res[l] = res[l] + (s_vector[j_tag]*2*modularity_matrix[l][j_tag]);
                }
            }
            /* printf("multiplyMatrixAndVector - Algo 4 : %f seconds\n", iter_time); */
            start = clock();
            while (curr)
            {
                score[curr->val] = -4*s_vector[curr->val] * res[curr->val] + 4*modularity_matrix[curr->val][curr->val];
                curr = curr->next;
            }
            iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            /*printf("Score calc - Algo 4 : %f seconds\n", iter_time);*/
            curr = unmoved;
            tmp = -DBL_MAX;
            start = clock();
            while (curr)
            {
                if(score[curr->val] > tmp)
                {
                    tmp = score[curr->val];
                    j_tag = curr->val;
                }
                curr = curr->next;
            }
            iter_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            /*printf("Finding max - Algo 4 : %f seconds\n", iter_time);*/

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
        printf("Improvement delta: %f\n",delta_q);
        freeList(unmoved);
        freeList(curr);
    }
    free(res);
    free(score);
    free(indices);
    free(improvement);
    printf("bla %f",iter_time);

}
