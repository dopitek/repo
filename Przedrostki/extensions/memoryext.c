#include "memoryext.h"

void realloc_if_exeeds(char** buffer, size_t current_position, size_t* size)
{
    if(current_position == *size)
    {
        *size *= 2;
        (*buffer) = realloc(*buffer, *size+1);
    }
}
