#include <stdio.h>
#include "queue.h"

// User Implementation level functions prototypes
type last_ui(Queue* q);
type first_ui(Queue* q);
void copy_ui(Queue* src, Queue* dest);
int size_ui(Queue* q);
void destroy_ui(Queue* q);

int main()
{
    Queue* q;
    createQueue(q);

    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 15);
    enqueue(q, 16);
    enqueue(q, 17);
    enqueue(q, 18);
    enqueue(q, 19);

    printf("Create the first Queue\n");
    printQueue(q);
    printf("Size: %d\n", size(q));
    printf("IsEmpty: %d\n", isEmpty(q));
    printf("IsFull: %d\n", isFull(q));
    printf("Last Element in implementation level: %d\n", last(q));

    printf("\nDequeue some elements from the Queue\n");
    printf("Dequeued: %d\n", deque(q));
    printf("Dequeued: %d\n", deque(q));
    printf("Dequeued: %d\n", deque(q));

    printQueue(q);
    printf("Size: %d\n", size(q));

    // Copy queue
    Queue* q2;
    copyQueue(q, q2);
    printf("\nQ2 after copy from Q\n");
    printQueue(q2);

    // Destroy q2
    destroy(q2);
    printf("\nQ2 after destroy\n");
    printQueue(q2);
    printf("q2 size after destroy: %d\n", size(q2));

    // User Level
    printf("\nDequeue User Level Functions\n");
    printf("Last Element in user level: %d\n", last_ui(q));
    printf("First Element in user level: %d\n", first_ui(q));

    createQueue(q2);
    copy_ui(q, q2);
    printf("Copy Queue1 into Queue2\n");
    printQueue(q2);

    destroy_ui(q2);
    printf("Destroy Queue in user level\n");
    printQueue(q2);
    
    return 0;
}


type last_ui(Queue* q)
{
    type last_element;
    Queue* temp;
    createQueue(temp);

    while (!isEmpty(q)) {
        last_element = deque(q);
        enqueue(temp, last_element);
    }

    while (!isEmpty(temp))
        enqueue(q, deque(temp));

    return last_element;
}

type first_ui(Queue* q)
{
    type first_element = deque(q);

    Queue temp;
    createQueue(&temp);
    enqueue(&temp, first_element);

    while (!isEmpty(q))
        enqueue(&temp, deque(q));

    while (!isEmpty(&temp))
        enqueue(q, deque(&temp));

    return first_element;
}

void destroy_ui(Queue* q)
{
    while (!isEmpty(q))
        deque(q);
}

void copy_ui(Queue* q1, Queue* q2)
{
    createQueue(q2);
    
    Queue temp;
    createQueue(&temp);

    while (!isEmpty(q1)) {
        type element = deque(q1);
        enqueue(&temp, element);
        enqueue(q2, element);
    }

    while (!isEmpty(&temp))
        enqueue(q1, deque(&temp));
}

int size_ui(Queue* q)
{
    int count = 0;
    Queue temp;
    createQueue(&temp);

    while (!isEmpty(q)) {
        enqueue(&temp, deque(q));
        count++;
    }

    while (!isEmpty(&temp))
        enqueue(q, deque(&temp));

    return count;
}


