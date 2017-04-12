#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stringext.h"




int strcmp_ignore_case(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}

stack* split(char *line, char *delimiter)
{
    char *pch;
    stack* result = initialize_stack();

    pch = strtok (line, delimiter);
    while (pch != NULL)
    {
        if(pch[0]!='\0')
        {
            push(&result, pch);
        }
        pch = strtok (NULL, delimiter);
    }
    return result;
}



