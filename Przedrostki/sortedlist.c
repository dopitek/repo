#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sortedlist.h"
#include "stringext.h"


word* initialize_list()
{
    word* head = (word*)malloc(sizeof(word));
    head->next = NULL;
    return head;
}

void add_element(word* head, char* text)
{
    word* temp = head;
    word* new_element;

    if (temp->next != NULL)
    {
        while(temp->next != NULL && strcmp_ignore_case(temp->next->text, text) <0 )
            temp = temp->next;
    }

    if (temp->next == NULL || strcmp_ignore_case(temp->next->text, text) != 0)
    {
        new_element = (word*)malloc(sizeof(word));
        new_element->text = text;
        new_element->next = temp->next;
        temp->next = new_element;
    }
    else{
        free(text);
    }
}

void destroy_list(word* head)
{

    word* temp, *temp2;
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

void print_list(word* head)
{

    word* temp = head->next;
    while(temp !=NULL)
    {
        printf("%s\n", temp->text);
        temp = temp->next;
    }
}
