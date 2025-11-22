#include <stdio.h>
#include "list.h"

void createList(List* l)
{
    l->size = 0;
}

void insert(List* l, type element, int index)
{
    if(index > l->size || index < 0)
    {
        printf("The Last index is %d! Choose between it.\n", l->size);
        return;
    }

    if(l->size >= MAX_SIZE)
    {
        printf("List Overflow! Can Not Insert %d\n", element);
        return;
    }

    for (int i = l->size; i > index; i--)
        l->arr[i] = l->arr[i - 1];

    l->arr[index] = element;
    l->size++;
}


type retrieve(List* l, int index)
{
    if (index < 0 || index >= l->size) {
        printf("Index out of bounds! Size: %d, Index: %d\n", l->size, index);
        return -99999;
    }

    int element = l->arr[index];

    for(int i = index; i < l->size - 1; i++)
       l->arr[i] = l->arr[i + 1];

    l->size--;
    return element;
}

int isEmpty(List* l)
{
    return l->size <= 0;
}

int size(List* l)
{
    return l->size;
}

void destroy(List* l)
{
    l->size = 0;
}

void printList(List* l)
{
    if(isEmpty(l))
    {
        printf("List is Empty\n");
        return;
    }

    for (int i = 0; i < l->size; i++)
        printf("%d ", l->arr[i]);

    printf("\n");
}
