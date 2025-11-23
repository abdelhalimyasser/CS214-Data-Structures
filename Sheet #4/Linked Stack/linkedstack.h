#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

typedef int type;

typedef struct Node
{
    type data;
    struct Node* next;
} Node;

typedef struct
{
    Node* top;
    int size;
} Stack;

void createLinkedStack(Stack* s);

void push(Stack* s, int element);

type pop(Stack* s);

type peek(Stack* s);

int isEmpty(Stack* s);

int size(Stack* s);

void print(Stack* s);

void clearStack(Stack* s);

#endif // LINKEDSTACK_H_INCLUDED
