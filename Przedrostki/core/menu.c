#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "resources.h"
#include "../extensions/fileext.h"

model menu(int argc, char ** argv)
{
    int i;
    model model_t;

    if (argc == 2 && strcmp(argv[1], "-h") == 0)
    {
        printf("%s\n", HELP);
        model_t.valid = false;
        return model_t;
    }
    else
    {
        for(i=1;i<argc;i++)
        {
            if (argv[i][0] == '-')
            {
                if (argv[i][1] == 'p' && i+1<argc && argv[i+1][0] != '-')
                    model_t.prefix = argv[i+1];
                if (argv[i][1] == 'o' && i+1<argc && argv[i+1][0] != '-')
                    model_t.out_filename = argv[i+1];
                if (argv[i][1] == 'i' && i+1<argc && argv[i+1][0] != '-')
                    model_t.in_filename = argv[i+1];
            }
        }
    }
    model_t.valid = validate_input(model_t) == 0 ? true : false;
    return model_t;
}

int check_for_null(char *string, char *error_message)
{
    if (string == NULL)
    {
        printf("%s\n", error_message);
        return -1;
    }
    return 0;
}

int validate_prefix_parameter(char * prefix)
{
    return check_for_null(prefix, PREFIX_MISSING);
}

int validate_input_file_parameter(char * input_file_name)
{
    if (check_for_null(input_file_name, INPUT_FILE_NAME_MISSING) != 0) return -1;
    else
    {
        if (!file_exists(input_file_name))
        {
            printf("%s\n", INPUT_FILE_MISSING);
            return -1;
        }
    }
    return 0;
}

int validate_output_file_parameter(char * output_file_name)
{
    if (check_for_null(output_file_name, OUTPUT_FILE_NAME_MISSING) != 0) return -1;
    return 0;
}



int validate_input(model model_t)
{
    if (validate_prefix_parameter(model_t.prefix) != 0) return -1;
    if (validate_input_file_parameter(model_t.in_filename) != 0) return -1;
    if (validate_output_file_parameter(model_t.out_filename) != 0) return -1;

    return 0;
}


