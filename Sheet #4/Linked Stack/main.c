#include <stdio.h>
#include "linkedstack.h"

int main()
{
    Stack s;
    createLinkedStack(&s);

    printf("Is empty? %d\n", isEmpty(&s));

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    print(&s);
    printf("Top element: %d\n", peek(&s));
    printf("Size: %d\n", size(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    print(&s);

    clearStack(&s);
    printf("After clear - empty? %d\n", isEmpty(&s));
    return 0;
}
