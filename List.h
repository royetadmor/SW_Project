
#ifndef SW_PROJECT_LIST_H
#define SW_PROJECT_LIST_H

typedef struct list{
    int val;
    struct list* next;
}list;
void add(int val, list* head);
list* removeNode(int val, list* head);
list* getNode(int val, list* head);
int ListSize(list* head);
list* init_list();
#endif
