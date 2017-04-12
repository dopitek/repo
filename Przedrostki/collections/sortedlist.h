#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

#include "../common.h"

typedef struct sorted_list
{
    char* text;
    struct sorted_list* next;
} sorted_list;

sorted_list* initialize_list();
void add_element(sorted_list* head, char* text);
void destroy_list(sorted_list* head);
void print_list(sorted_list* head);

#endif
