#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stringext.h"

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


int strcmp_ignore_case(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}


