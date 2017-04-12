#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "prefix.h"
#include "collections\sortedlist.h"
#include "collections\stack.h"
#include "extensions\stringext.h"
#include "extensions\fileext.h"

void read(char * filename, char * prefix)
{
    FILE* file;
    char* line;
    char* element;

    stack* result;
    stack* result2;
    sorted_list* result3 = initialize_list();
    char* delimiter = " ,.:\r!?\"";


    if ((file = fopen(filename, "r")) != NULL)
    {
        while(!feof(file))
        {
            line = read_line(file);
            result = split(line, delimiter);
            result2 = select_many_with_prefix(&result, prefix);
            dealloc_stack(result);
            while((element = pop(&result2))!= NULL)
            {
                    add_element(result3, element);
            }
            dealloc_stack(result2);
            free(line);
        }
    }
    print_list(result3);
    destroy_list(result3);
}




