#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

#include "common.h"

word* initialize_list();
void add_element(word* head, char* text);
void destroy_list(word* head);
void print_list(word* head);

#endif
