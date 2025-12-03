#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"

void createQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue* q, char* id, int priority)
{
    Process* newProcess = (Process* )malloc(sizeof(Process));

    strcpy(newProcess->processID, id);
    newProcess->priority  = priority;

    if(q->front == NULL || priority < q->front->priority)
    {
        newProcess->next = q->front;
        q->front = newProcess;

        if(q->rear == NULL)
            q->front = q->rear = newProcess;
    }
    else
    {
        Process* curr = q->front;

        while (curr->next != NULL && curr->next->priority <= priority)
            curr = curr->next;

        newProcess->next = curr->next;
        curr->next = newProcess;

        if(newProcess->next == NULL)
            q->rear = newProcess;
    }

    q->size++;
}

void dequeue(Queue* q)
{
    if (q->front == NULL)
    {
        printf("No processes to serve.\n");
        return;
    }

    Process* temp = q->front;
    printf("Serving process %s with priority %d\n", temp->processID, temp->priority);

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    q->size--;
}

void clear(Queue* q)
{
    Process* temp = q->front;

    while (temp != NULL)
    {

        q->front = q->front->next;
        free(temp);
        temp = q->front;
    }

    createQueue(q);
}

int size(Queue* q)
{
    return q->size;
}
