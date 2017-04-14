#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "common.h"

model menu(int argc, char ** argv);
int validate_input(model model_t);
int validate_prefix_parameter(char * prefix);
int validate_input_file_parameter(char * input_file_name);
int validate_output_file_parameter(char * output_file_name);
int check_for_null(char *string, char *error_message);

#endif
