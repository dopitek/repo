#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct stack
{
    char* object;
    struct stack* next;
} stack;

stack* initialize_stack();
void push(stack** head, char* object);
char* pop(stack** head);
void dealloc_stack(stack* head);

#endif
