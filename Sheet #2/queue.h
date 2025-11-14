#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX_SIZE 10

typedef int type;
typedef struct
{
    type arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void createQueue(Queue* q);
void enqueue(Queue* q, type element);
type deque(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
int size(Queue* q);
void destroy(Queue* q);
void printQueue(Queue* q);
void copyQueue(Queue* q1, Queue* q2);
type last(Queue* q);

#endif // QUEUE_H_INCLUDED
