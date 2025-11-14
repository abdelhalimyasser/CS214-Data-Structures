#include <stdio.h>
#include "global.h"
#include "stack.h"
#include "queue.h"

int main()
{
    Stack s;
    Queue q;
    Customer c;

    createStack(&s);
    createQueue(&q);

    int choice;

    while (1)
    {
        printf("\n1. Add a New Customer\n");
        printf("2. Serve a Customer\n");
        printf("3. Display Customers Information\n");
        printf("4. Display Customers in Most-Recent Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter The Name: ");
            scanf("%s", c.name);
            printf("Enter The Id: ");
            scanf("%d", &c.id);
            enqueue(&q, c);
        }
        else if (choice == 2)
        {
            if (!isEmptyQueue(&q))
            {
                c = dequeue(&q);
                printf("Serving Customer: %s, ID: %d\n", c.name, c.id);
            }
            else
            {
                printf("No customers to serve.\n");
            }
        }
        else if (choice == 3)
        {
            displayQueue(&q);
        }
        else if (choice == 4)
        {
            createStack(&s);

            if (isEmptyQueue(&q))
            {
                printf("No customers to display.\n");
            }
            else
            {
                for (int i = 0; i < q.count; i++)
                {
                    int index = (q.front + i) % MAX_SIZE;
                    push(&s, q.arr[index]);
                }

                printf("Customers in Most-Recent Order=:\n");
                displayStack(&s);
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid Choice, Please Try Again.\n");
        }
    }
    return 0;
}
