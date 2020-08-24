/*
 * Created by Roye on 06/08/2020.
 */

#include "spmat.h"
#include <stdio.h>
#include <stdlib.h>
void add_row_list(spmat* A, double* row, int i);
void list_free(spmat* A);
void mult_list (spmat *A, double *v, double *result);

typedef struct list{
    double val;
    int col_index;
    struct list* next;
}list;

spmat* spmat_allocate_list(int n)
{
    int i;
    list** arr;
    spmat* A;
    arr = (list**)malloc(n* sizeof(list*));
    for (i = 0; i < n; ++i) {
        arr[i] = (list*)malloc(sizeof(list));
        arr[i]->val = 0;
        arr[i]->col_index = -1;
        arr[i]->next = NULL;
    }
    A = (spmat*)malloc(sizeof(spmat));
    A->n = n;
    A->add_row = &add_row_list;
    A->free = &list_free;
    A->mult = &mult_list;
    A->private = arr;
    return A;
}

void add_row_list(spmat* A, double* row, int i)
{
    int j;
    list** arr;
    list *head;
    arr = A->private;
    for (j = 0; j < A->n ; ++j) {
        if (row[j] != 0) {
            head = arr[i];
            while (head->next) {
                head = head->next;
            }
            head->next = (list *) malloc(sizeof(list));
            head->next->val = row[j];
            head->next->col_index = j;
            head->next->next = NULL;
        }
    }
}
void list_free(spmat* A)
{
    int i;
    for (i = 0; i < A->n; ++i) {
        free(((list**)A->private)[i]);
    }
    free(A->private);
    free(A);
}
void mult_list (spmat *A, double *v, double *result)
{
    int i, row;
    list** arr;
    double sum;
    list* curr;
    arr = A->private;
    for (i = 0; i < A->n; ++i) {
        sum = 0;
        for (row = 0; row < A->n; ++row) {
            curr = arr[row];
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
