#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

stack* initialize_stack()
{
    stack* head = (stack*)malloc(sizeof(stack));
    head->next = NULL;
    return head;
}

void push(stack** head, char* object)
{
    stack* new_element = (stack*)malloc(sizeof(stack));
    new_element->object = calloc(strlen(object)+1, 1);
    strcpy(new_element->object, object);
    new_element->next = *head;
    *head = new_element;
}

char* pop(stack** head)
{
    stack* temp;
    char* object;

    if ((*head)->next != NULL)
    {
        temp = *head;
        object = calloc(strlen(temp->object)+1, 1);
        strcpy(object, temp->object);
        //object = temp->object;
        (*head) = (*head)->next;
        free(temp->object);
        free(temp);
        return object;
    }

    return NULL;
}

void print_stack(stack* head)
{
    stack* temp = head;
    while(temp->next != NULL)
    {
        printf("%s\n",temp->object);
        temp = temp->next;
    }
}

void destroy(stack* head)
{

    stack* temp;
    if (head == NULL) return;
    while(head->next != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->object);
        free(temp);
    }

    free(head);
    head = NULL;
}
