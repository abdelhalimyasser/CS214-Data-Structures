#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

int main()
{
    Queue* q;
    createQueue(q);

    printf("Is empty? %d\n", isEmpty(q));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    print(q);
    printf("Size: %d\n", size(q));
    printf("Front: %d\n", peek(q));

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    print(q);

    destroyQueue(q);
    printf("After destroy, empty? %d\n", isEmpty(q));

    return 0;
}
