#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "common.h"

typedef struct stack
{
    char* object;
    struct stack* next;
} stack;

stack* initialize_stack();
void push(stack** head, char* object);
char* pop(stack** head);
void destroy(stack* head);

void print_stack(stack* head);

#endif
