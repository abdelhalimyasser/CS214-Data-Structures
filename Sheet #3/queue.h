#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "global.h"

void createQueue(Queue* q);
void enqueue(Queue* q, Customer element);
int isEmptyQueue(Queue* q);
Customer dequeue(Queue* q);
Customer peekQueue(Queue* q);
void displayQueue(Queue* q);

#endif // QUEUE_H_INCLUDED
