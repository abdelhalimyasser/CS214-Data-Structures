#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

typedef struct Process
{
    char processID[10];
    int priority;
    struct Process* next;
} Process;

typedef struct Queue
{
    Process* front;
    Process* rear;
    int size;
} Queue;

void createQueue(Queue* q);

void enqueue(Queue* q, char* id, int priority);

void dequeue(Queue* q);

void clear(Queue* q);

int size(Queue* q);

#endif // PRIORITYQUEUE_H_INCLUDED
