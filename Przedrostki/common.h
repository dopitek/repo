#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    char* in_filename;
    char* out_filename;
    char* prefix;
    bool valid;
} model;

typedef struct word
{
    char* text;
    struct word* next;
} word;



#endif
