#include <stdio.h>
#include "global.h"

void createQueue(Queue* q)
{
    q->count = 0;
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue* q, Customer element)
{
    if (q->count >= MAX_SIZE)
    {
        printf("Queue is full! Cannot add more customers.\n");
        return;
    }

    if (q->count == 0)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->arr[q->rear] = element;
    q->count++;
}

int isEmptyQueue(Queue* q)
{
    return q->count == 0;
}

Customer dequeue(Queue* q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty! No customer to serve.\n");
        Customer empty = {"", -1};
        return empty;
    }

    Customer element = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;

    if (q->count == 0)
    {
        q->front = -1;
        q->rear = -1;
    }

    return element;
}

Customer peekQueue(Queue* q)
{
    return q->arr[q->front];
}


void displayQueue(Queue* q)
{
    if (isEmptyQueue(q))
    {
        printf("No customers in queue.\n");
        return;
    }

    printf("Current Queue:\n");
    for (int i = 0; i < q->count; i++)
    {
        int index = (q->front + i) % MAX_SIZE;
        printf("  %s | ID: %d\n", q->arr[index].name, q->arr[index].id);
    }
}
