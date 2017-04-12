#include <stdlib.h>
#include <ctype.h>
#include "prefix.h"

stack* select_many_with_prefix(stack ** matches, char *prefix)
{
    stack* result = initialize_stack();
    char* element;

    while((element = pop(matches))!= NULL)
    {
        if (element[0] != '\0' && has_prefix_ignore_case(element, prefix) == 0)
        {
            push(&result, element);
        }
        free(element);
    }
    return result;
}

int has_prefix_ignore_case(char const *text, char const *prefix)
{
    int result;
    if (text == NULL || prefix == NULL) return 1;
    for (;; prefix++, text++) {
        if (!*prefix) return 0;
        result = tolower(*prefix) - tolower(*text);
        if (result != 0)
            return result;
    }
    return 0;
}
