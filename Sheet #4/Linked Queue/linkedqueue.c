#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void createQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue* q, type element)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = element;

    if(q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

type dequeue(Queue* q)
{
    type element = q->front->data;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear == NULL;

    q->size--;

    return element;
}

type peek(Queue* q)
{
    return q->front->data;
}

void print(Queue* q)
{
    Node* temp = q->front;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty(Queue* q)
{
    return q->front == NULL;
}

int size(Queue* q)
{
    return q->size;
}

void destroyQueue(Queue* q)
{
    Node* temp = q->front;

    while (q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}
