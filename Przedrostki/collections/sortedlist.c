#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sortedlist.h"
#include "../extensions/stringext.h"


sorted_list* initialize_list()
{
    sorted_list* head = (sorted_list*)malloc(sizeof(sorted_list));
    head->next = NULL;
    return head;
}

void add_element(sorted_list* head, char* text)
{
    sorted_list* temp = head;
    sorted_list* new_element;

    if (temp->next != NULL)
    {
        while(temp->next != NULL && strcmp_ignore_case(temp->next->text, text) <0 )
            temp = temp->next;
    }

    if (temp->next == NULL || strcmp_ignore_case(temp->next->text, text) != 0)
    {
        new_element = (sorted_list*)malloc(sizeof(sorted_list));
        new_element->text = text;
        new_element->next = temp->next;
        temp->next = new_element;
    }
    else{
        free(text);
    }
}

void destroy_list(sorted_list* head)
{

    sorted_list* temp, *temp2;
    temp = head;
    head=head->next;
       while(head != NULL)
       {
        temp2 = head;
        head = head->next;
        free(temp2->text);
        free(temp2);
       }
    free(temp);
}

void print_list(sorted_list* head)
{
    sorted_list* temp = head->next;
    while(temp !=NULL)
    {
        printf("%s\n", temp->text);
        temp = temp->next;
    }
}
