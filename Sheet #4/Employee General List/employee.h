#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define MAX_NAME   50
#define MAX_CITY   50
#define MAX_STREET 100

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

typedef struct Address
{
    char street[MAX_STREET];
    char city[MAX_CITY];
    int zip;
} Address;

typedef struct Company
{
    char name[MAX_NAME];
    int phone;
    Address* companyAddress;
} Company;

typedef struct Entry
{
    char name[MAX_NAME];
    Address* homeAddress;
    Date* dateOfBirth;
    Company* company;
} Entry;

typedef struct Node
{
    Entry* data;
    struct Node* next;
} Node;

typedef struct EntryList
{
    int size;
    Node* head;
} EntryList;


void createEntryList(EntryList* list);

void insertEntry(EntryList* list,
                 char* empName,
                 char* homeStreet, char* homeCity, int homeZip,
                 int day, int month, int year,
                 char* compName, char* compStreet,
                 char* compCity, int compZip, int compPhone);

Entry* retrieveEntry(EntryList* list, int index);

void printEntryList(EntryList* list);

int isEmptyEntryList(EntryList* list);

int sizeEntryList(EntryList* list);

void clearEntryList(EntryList* list);

#endif // EMPLOYEE_H_INCLUDED
