#include<stdio.h>
#include"queue.h"

void createQueue(Queue* q)
{
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue* q, type element)
{
    if(q->size >= MAX_SIZE)
    {
        printf("Queue Overflow.\n");
        return;
    }

    if(q->rear == -1 && q->front == -1)
        q->rear = q->front = q->size = 0;

    q->arr[q->rear] = element;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->size++;
}

type deque(Queue* q)
{
    if(q->size <= 0)
    {
        printf("Queue Ünderflow.\n");
        return -9999;
    }

    type element = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;

    return element;
}

int isEmpty(Queue* q)
{
    return q->size <= 0;
}

int isFull(Queue* q)
{
    return q->size == MAX_SIZE;
}

int size(Queue* q)
{
    return q->size;
}

void destroy(Queue* q)
{
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

void printQueue(Queue* q)
{
    if(q->size <= 0)
    {
        printf("Queue is Empty.\n");
        return;
    }

    for(int i = 0; i < q->size; i++)
        printf("%d ", q->arr[(q->front + i) % MAX_SIZE]);

    printf("\n");
}

void copyQueue(Queue* q1, Queue* q2)
{
    createQueue(q2);
    for(int i = 0; i < q1->size; i++)
        q2->arr[(q2->rear + i) % MAX_SIZE] = q1->arr[(q1->front + i) % MAX_SIZE];

    q2->size = q1->size;
    q2->rear = (q2->rear + q1->size) % MAX_SIZE;
}

type last(Queue* q)
{
    int last = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return q->arr[last];
}
