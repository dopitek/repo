#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "error.h"
#include "../extensions/fileext.h"

int check_for_null(char *string, char *error_message)
{
    if (string == NULL)
    {
        printf("%s\n", error_message);
        return -1;
    }
    return 0;
}

int validate_prefix_parameter(char * prefix, message message_t)
{
    return check_for_null(prefix, message_t.prefix_missing);
}

int validate_input_file_parameter(char * input_file_name, message message_t)
{
    if (check_for_null(input_file_name, message_t.input_file_name_missing) != 0) return -1;
    else
    {
        if (!file_exists(input_file_name))
        {
            printf("%s\n", message_t.input_file_missing);
            return -1;
        }
    }
    return 0;
}

int validate_output_file_parameter(char * output_file_name, message message_t)
{
    if (check_for_null(output_file_name, message_t.output_file_name_missing) != 0) return -1;
    else
    {
        //if (!file_exists(output_file_name))
        //{
        //    printf("%s\n", message_t.output_file_missing);
        //    return -1;
        //}
    }
    return 0;
}

int validate_input(model model_instance)
{
    message message_t = load_error_messages();

    if (validate_prefix_parameter(model_instance.prefix, message_t) != 0) return -1;
    if (validate_input_file_parameter(model_instance.in_filename, message_t) != 0) return -1;
    if (validate_output_file_parameter(model_instance.out_filename, message_t) != 0) return -1;

    return 0;
}

int menu(int argc, char ** argv, model *model_instance)
{
    int i;

    for(i=1;i<argc;i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'p' && i+1<argc)
                model_instance->prefix = argv[i+1];
            if (argv[i][1] == 'o' && i+1<argc)
                model_instance->out_filename = argv[i+1];
            if (argv[i][1] == 'i' && i+1<argc)
                model_instance->in_filename = argv[i+1];
        }
    }

    return validate_input(*model_instance);
}


