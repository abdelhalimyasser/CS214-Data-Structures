#include <stdio.h>
#include "list.h"

void createList(List* l) {
	l->size = 0;
}

void insert(List* l, type element, int index) {
}

type retrive(List* l, int index) {
}

int isEmpty(List* l) {
	return l->size <= 0;
}

int size(List* l) {
	return l->size;
}

void destroy(List* l) {
	l->size = 0;
}

void printList(List* l) {
    if(isEmpty(l))
        printf("List is Empty\n");
        
	for (int i = 0; i < l->size; i++)
		printf("%d ", l->data[i]);
		
	printf("\n");
}
