#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

void add(int val, list* head)
{
    list* curr = head;
    if(curr->val == INT_MIN)
    {
        curr->val = val;
        return;
    }
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = (list*)malloc(sizeof(list));
    curr->next->val = val;
    curr->next->next = NULL;
}
list* removeNode(int val, list* head)
{
    list* curr = head;
    list* tmp = head;
    if (curr->val == val)
    {
        head = head->next;
        return head;
    }
    while (curr)
    {
        if(curr->next->val == val)
        {
            curr->next = curr->next->next;
            return head;
        } else
        {
            curr = curr->next;
        }
    }
    return tmp;
}
list* getNode(int val, list* head)
{
    list* curr = head;
    while (curr)
    {
        if(curr->val == val)
        {
            return curr;
        } else
        {
            curr = curr->next;
        }
    }
    return NULL;
}
int ListSize(list* head)
{
    int count;
    list* curr;
    curr = head;
    count = -1;
    while (curr)
    {
        ++count;
        curr = curr->next;
    }
    return count;
}
list* init_list()
{
    list* head;
    head = (list*)malloc(sizeof(list));
    head->next = NULL;
    head->val = INT_MIN;
    return head;
}

void printList(list* head)
{
    list* curr;
    curr = head;
    while (curr)
    {
        printf("%d -> ",curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}
int createArrayFromList(list *head, int *array){

	int i, length, value;

	list *node = head;
	length = ListSize(head);
	array = (int*)calloc(length, sizeof(int));
	for(i = 0 ; i < length ; i++){
		value = node->val;
		if(value == 0){
			return EXIT_FAILURE;
		}
		array[i] = value;
		head = head->next;
	}
	return EXIT_SUCCESS;
}

