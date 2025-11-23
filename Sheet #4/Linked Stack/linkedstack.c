#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

void createLinkedStack(Stack* s)
{
    s->size = 0;
    s->top = NULL;
}

void push(Stack* s, int element)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = element;
    newNode->next = s->top;
    s->top = newNode;

    s->size++;
}

type pop(Stack* s)
{
    Node* temp = s->top;
    type data = temp->data;
    temp = temp->next;

    s->top = s->top->next;
    free(temp);
    s->size--;

    return data;
}

type peek(Stack* s)
{
    return s->top->data;
}

int isEmpty(Stack* s)
{
    return s->top == NULL;
}

int size(Stack* s)
{
    return s->size;
}

void print(Stack* s)
{
    Node* temp = s->top;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void clearStack(Stack* s)
{
    Node* temp = s->top;

    while(temp != NULL)
    {
        temp = temp->next;
        free(temp);
    }

    s->size = 0;
    s->top = NULL;
}
