#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED
#include "common.h"
#include "../collections/sortedlist.h"

void process(model model_t);
void process_line(char *line, char* prefix, sorted_list* results);

#endif
