#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    char *in_filename;
    char *out_filename;
    char *prefix;
    bool valid;
} model;

model initialize_model();
void destroy_model(model model_instance);

#endif
