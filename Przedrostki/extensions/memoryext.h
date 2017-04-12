#ifndef MEMORYEXT_H_INCLUDED
#define MEMORYEXT_H_INCLUDED

#include <stdlib.h>

void realloc_if_exeeds(char** buffer, size_t current_position, size_t* size);

#endif
