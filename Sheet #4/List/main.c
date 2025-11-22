#include <stdio.h>
#include "list.h"

int main()
{
    List* list;
    createList(list);

    insert(list, 10, 0);
    insert(list, 11, 1);
    insert(list, 12, 2);
    insert(list, 13, 3);
    insert(list, 14, 2);

    printList(list);

    printf("The Retrieved: %d\n", retrieve(list, 2));

    printList(list);

    printf("Size: %d\n", size(list));

    destroy(list);

    printf("Is Empty: %d\n", isEmpty(list));

    return 0;
}
