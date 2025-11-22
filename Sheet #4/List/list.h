#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define MAX_SIZE 10

typedef int type;

typedef struct{
    type arr[MAX_SIZE];
    int size;
}List;

void createList(List* l);

void insert(List* l, type element, int index);

type retrive(List* l, int index);

int isEmpty(List* l);

int size(List* l);

void destroy(List* l);

void printList(List* l);

#endif // LIST_H_INCLUDED
