//
// Created by Roye on 24/08/2020.
//

#include "List.h"
#include <stdlib.h>
#include <stdio.h>

void add(int val, list* head)
{
    list* curr = head;
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
//int main()
//{
//    list* list1;
//    list* tmp;
//    list1 = (list*)malloc(sizeof(list));
//    list1->val = 0;
//    list1->next = NULL;
//    int i;
//    for (i = 0; i < 10; ++i) {
//        add(i+1,list1);
//    }
//    list1 = removeNode(0,list1);
//    list1 = removeNode(2,list1);
//    list1 = removeNode(7,list1);
//    tmp = getNode(-1,list1);
//    printf("Done %d",ListSize(list1));
//    return 0;
//}
