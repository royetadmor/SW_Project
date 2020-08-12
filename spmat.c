//
// Created by Roye on 06/08/2020.
//

#include "spmat.h"
#include <stdio.h>
#include <stdlib.h>
void add_row_list(spmat* A, double* row, int i);
void list_free(spmat* A);
void mult_list (spmat *A, double *v, double *result);
void printmat(spmat* A);

typedef struct list{
    double val;
    int col_index;
    struct list* next;
}list;

spmat* spmat_allocate_list(int n)
{
    list** arr = (list**)malloc(n* sizeof(list));
    for (int i = 0; i < n; ++i) {
        arr[i] = (list*)malloc(sizeof(list));
        arr[i]->val = 0;
        arr[i]->col_index = -1;
        arr[i]->next = NULL;
    }
    spmat* A = (spmat*)malloc(sizeof(spmat));
    A->n = n;
    A->add_row = &add_row_list;
    A->free = &list_free;
    A->mult = &mult_list;
    A->private = arr;
    return A;
}

void add_row_list(spmat* A, double* row, int i)
{
    list** arr = A->private;
    for (int j = 0; j < A->n ; ++j) {
        if (row[j] != 0) {
            list *head = arr[i];
            while (head->next) {
                head = head->next;
            }
            head->next = (list *) calloc(1, sizeof(list));
            head->next->val = row[j];
            head->next->col_index = j;
            head->next->next = NULL;
        }
    }
}
void list_free(spmat* A)
{
    for (int i = 0; i < A->n; ++i) {
        list* curr = ((list**)A->private)[i];
        free(curr);
    }
    free(A->private);
    free(A);
}

void mult_list (spmat *A, double *v, double *result)
{
    list** arr = A->private;
    for (int i = 0; i < A->n; ++i) {
        double sum = 0;
        for (int row = 0; row < A->n; ++row) {
            list* curr = arr[row];
            while (curr != NULL && i != curr->col_index)
            {
                curr = curr->next;
            }
            if(curr != NULL)
            {
                sum += (curr->val * v[row]);
            }


        }
        result[i] = sum;
    }

}

//void printmat(spmat* A)
//{
//    for (int i = 0; i < A->n; ++i) {
//        list* node = ((list**)A->private)+i;
//        while (node != NULL)
//        {
//            printf("%d ",node->val);
//            node = node->next;
//        }
//        printf("\n");
//
//    }
//}
//
