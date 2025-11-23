#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main() {
    EntryList list;
    createEntryList(&list);

    insertEntry(&list,
                "First Sur1",
                "123 Main St", "Cairo", 10001,
                15, 3, 1990,
                "ABC", "123 Tech Road", "New Capital", 90001, 55512345);

    insertEntry(&list,
                "First Sur2",
                "678 Main St", "Giza", 60601,
                22, 11, 1985,
                "XYZ", "789 Tech Road", "Smart Village", 94105, 55598765);

    printEntryList(&list);

    clearEntryList(&list);
    return 0;
}
