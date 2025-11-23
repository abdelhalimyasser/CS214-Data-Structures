#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

void createEntryList(EntryList* list)
{
    list->head = NULL;
    list->size = 0;
}

void insertEntry(EntryList* list,
                 char* empName,
                 char* homeStreet, char* homeCity, int homeZip,
                 int day, int month, int year,
                 char* compName, char* compStreet,
                 char* compCity, int compZip, int compPhone)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (Entry*)malloc(sizeof(Entry));
    newNode->data->homeAddress = (Address*)malloc(sizeof(Address));
    newNode->data->dateOfBirth = (Date*)malloc(sizeof(Date));
    newNode->data->company = (Company*)malloc(sizeof(Company));
    newNode->data->company->companyAddress = (Address*)malloc(sizeof(Address));

    strncpy(newNode->data->name, empName, MAX_NAME - 1);
    newNode->data->name[MAX_NAME - 1] = '\0';

    strncpy(newNode->data->homeAddress->street, homeStreet, MAX_STREET - 1);
    newNode->data->homeAddress->street[MAX_STREET - 1] = '\0';
    strncpy(newNode->data->homeAddress->city, homeCity, MAX_CITY - 1);
    newNode->data->homeAddress->city[MAX_CITY - 1] = '\0';
    newNode->data->homeAddress->zip = homeZip;

    newNode->data->dateOfBirth->day = day;
    newNode->data->dateOfBirth->month = month;
    newNode->data->dateOfBirth->year = year;

    strncpy(newNode->data->company->name, compName, MAX_NAME - 1);
    newNode->data->company->name[MAX_NAME - 1] = '\0';

    strncpy(newNode->data->company->companyAddress->street, compStreet, MAX_STREET - 1);
    newNode->data->company->companyAddress->street[MAX_STREET - 1] = '\0';
    strncpy(newNode->data->company->companyAddress->city, compCity, MAX_CITY - 1);
    newNode->data->company->companyAddress->city[MAX_CITY - 1] = '\0';
    newNode->data->company->companyAddress->zip = compZip;
    newNode->data->company->phone = compPhone;

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Entry* retrieveEntry(EntryList* list, int index)
{

    Node* temp = list->head;

    for (int i = 0; i < index && temp != NULL; i++)
        temp = temp->next;

    return temp->data;

}

void printEntryList(EntryList* list)
{
    Node* current = list->head;
    int i = 0;
    while (current != NULL)
    {
        Entry* e = current->data;

        printf("\n--- Employee %d ---\n", ++i);
        printf("Name         : %s\n", e->name);

        printf("Home Address : %s, %s %d\n",
               e->homeAddress->street,
               e->homeAddress->city,
               e->homeAddress->zip);

        printf("Date of Birth: %02d/%02d/%d\n",
               e->dateOfBirth->day,
               e->dateOfBirth->month,
               e->dateOfBirth->year);

        printf("Company      : %s\n", e->company->name);

        printf("Company Add. : %s, %s %d\n",
               e->company->companyAddress->street,
               e->company->companyAddress->city,
               e->company->companyAddress->zip);

        printf("Company Phone: %d\n", e->company->phone);

        current = current->next;
    }
}

int isEmptyEntryList(EntryList* list)
{
    return list->size == 0;
}

int sizeEntryList(EntryList* list)
{
    return list->size;
}

void clearEntryList(EntryList* list)
{
    Node* temp = list->head;

    while(temp != NULL)
    {
        Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    list->head = NULL;
    list->size = 0;
}
