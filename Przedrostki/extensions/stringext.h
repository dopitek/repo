#ifndef STRINGEXT_H_INCLUDED
#define STRINGEXT_H_INCLUDED

#include "../collections/stack.h"

int strcmp_ignore_case(char const *a, char const *b);
stack* split(char *line, char *delimiter);

#endif
