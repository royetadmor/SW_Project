<<<<<<< HEAD
=======
/*
 * Created by Roye on 24/08/2020.
 */
>>>>>>> c3aed3ebb7eef9e3007e3ca4141400ee8489debe

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
<<<<<<< HEAD
#endif
=======
void printList(list* head);
#endif /*SW_PROJECT_LIST_H*/
>>>>>>> c3aed3ebb7eef9e3007e3ca4141400ee8489debe
