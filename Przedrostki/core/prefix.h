#ifndef PREFIX_H_INCLUDED
#define PREFIX_H_INCLUDED

#include "../collections/stack.h"

int has_prefix_ignore_case(char const *text, char const *prefix);
stack* select_many_with_prefix(stack ** matches, char *prefix);

#endif
