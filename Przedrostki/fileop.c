#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileop.h"
#include "sortedlist.h"
#include "stack.h"
#include "stringext.h"

#define LINE_SIZE 1024
#define WORD_SIZE 512

void realloc_if_exeeds(char** buffer, size_t current_position, size_t* size)
{
    if(current_position == *size)
    {
        *size *= 2;
        (*buffer) = realloc(*buffer, *size+1);
    }
}

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




stack* parse_line(char *line)
{
    char *pch;
    stack* result = initialize_stack();

    pch = strtok (line," ,.:\r!?\"");
    while (pch != NULL)
    {
        if(pch[0]!='\0');
             push(&result, pch);

        pch = strtok (NULL, " ,.:\r!?\"");
    }
    return result;
}

stack* findddd(stack ** matches, char *prefix)
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

void read(char * filename, char * prefix)
{
    FILE* file;
    char* line;
    char* element;
    stack* result;
    stack* result2;
    word* result3 = initialize_list();


    if ((file = fopen(filename, "r")) != NULL)
    {
        while(!feof(file))
        {
            line = read_line(file);
            result = parse_line(line);
            result2 = findddd(&result, prefix);
            destroy(result);
            while((element = pop(&result2))!= NULL)
            {
                    add_element(result3, element);
            }
            destroy(result2);
            free(line);
        }
    }
    print_list(result3);
    destroy_list(result3);
    //return result3;
}




