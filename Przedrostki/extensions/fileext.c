#include <stdio.h>
#include <stdlib.h>
#include "fileext.h"
#include "memoryext.h"

#define LINE_SIZE 1024

char* read_line(FILE* file)
{
    size_t line_size = (size_t)LINE_SIZE;
    char *buffer = calloc(line_size+1, sizeof(char));
    int length = 0;
    char ch = getc(file);
    while ((ch != '\n') && (ch != EOF))
    {
        buffer[length] = ch;

        length++;
        realloc_if_exeeds(&buffer, length, &line_size);
        ch = getc(file);
    }
    buffer[length] = '\0';
    return buffer;
}

int file_exists(const char *fileName)
{
    FILE *file;
    if ((file = fopen(fileName, "r")) != NULL)
    {
        fclose(file);
        return 1;
    }
    return 0;
}





