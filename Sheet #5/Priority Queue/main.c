#include <stdio.h>
#include "priorityQueue.h"

int main()
{
    Queue* q;
    createQueue(q);

    int choice;
    int priority;
    char id[10];

    while(1)
    {
        printf("\nCPU Scheduling Simulation\n");
        printf("1. Add a New Process\n");
        printf("2. Serve a Process\n");
        printf("3. Number of Waiting Processes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter Process ID: ");
            scanf("%s", id);
            printf("Enter Priority: ");
            scanf("%d", &priority);
            enqueue(q, id, priority);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            printf("Size: %d\n", size(q));
            break;
        case 4:
            printf("Exiting and Deleting your Processes, too!\n");
            clear(q);
            return 0;
        default:
            printf("Invalid Choice! Try again\n");
            break;
        }
    }

    return 0;
}
