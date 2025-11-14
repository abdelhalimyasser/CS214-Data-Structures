#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define MAX_SIZE 10

typedef struct
{
    char name[50];
    int id;
} Customer;

typedef struct
{
    Customer arr[MAX_SIZE];
    int top;
} Stack;

typedef struct
{
    Customer arr[MAX_SIZE];
    int count;
    int front;
    int rear;
} Queue;

#endif // GLOBAL_H_INCLUDED
