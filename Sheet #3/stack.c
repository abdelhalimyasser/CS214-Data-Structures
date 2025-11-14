#include <stdio.h>
#include "global.h"

void createStack(Stack* s)
{
    s->top = -1;
}

void push(Stack* s, Customer element)
{
    if(s->top < MAX_SIZE - 1)
    {
        s->arr[++s->top] = element;
    }
}

int isEmptyStack(Stack* s)
{
    return s->top == -1;
}

Customer pop(Stack* s)
{
    if (s->top >= 0)
        return s->arr[s->top--];
}

Customer peek(Stack* s)
{
    return s->arr[s->top];
}


void displayStack(Stack* s)
{
    if (isEmptyStack(s))
    {
        printf("No customers in stack.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("Customer Name: %s, ID: %d\n", s->arr[i].name, s->arr[i].id);
    }
}
