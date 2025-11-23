#ifndef LINKEDQUEUE_H_INCLUDED
#define LINKEDQUEUE_H_INCLUDED

typedef int type;

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
    int size;
} Queue;

void createQueue(Queue* q);

void enqueue(Queue* q, type element);

type dequeue(Queue* q);

type peek(Queue* q);

void print(Queue* q);

int isEmpty(Queue* q);

int size(Queue* q);

void destroyQueue(Queue* q);

#endif // LINKEDQUEUE_H_INCLUDED
