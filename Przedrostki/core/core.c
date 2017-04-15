#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "prefix.h"
#include "resources.h"
#include "../collections/stack.h"
#include "../extensions/stringext.h"
#include "../extensions/fileext.h"

void process(model model_t)
{
    FILE* file_read;
    char* line;
    sorted_list* sorted_words_with_prefix;

    if ((file_read = fopen(model_t.in_filename, "r")) != NULL)
    {
        sorted_words_with_prefix = initialize_list();
        while(!feof(file_read))
        {
            line = read_line(file_read);
            process_line(line, model_t.prefix, sorted_words_with_prefix);
        }
        save_list(sorted_words_with_prefix, model_t.out_filename);
        destroy_list(sorted_words_with_prefix);
        fclose(file_read);
    }
    else
    {
        printf("%s\n", INPUT_FILE_CANNOT_BE_OPENED);
    }
}

void process_line(char *line, char* prefix, sorted_list* results)
{
    stack* words;
    stack* words_with_prefix;
    char* element;
    char* delimiter = " ,.:;\r!?\"(){}";

    words = split(line, delimiter);
    words_with_prefix = select_many_with_prefix(&words, prefix);
    while((element = pop(&words_with_prefix))!= NULL)
    {
            add_element(results, element, strcmp_ignore_case);
    }
    dealloc_stack(words);
    dealloc_stack(words_with_prefix);
    free(line);
}

