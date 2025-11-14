#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "global.h"

void createStack(Stack* s);
void push(Stack* s, Customer element);
int isEmptyStack(Stack* s);
Customer pop(Stack* s);
Customer peek(Stack* s);
void displayStack(Stack* s);

#endif // STACK_H_INCLUDED
