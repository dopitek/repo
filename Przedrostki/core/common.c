#include <stdlib.h>
#include "common.h"

model initialize_model()
{
    model model_instance;
    model_instance.in_filename = NULL;
    model_instance.out_filename = NULL;
    model_instance.prefix = NULL;
    return model_instance;
}

void destroy_model(model model_instance)
{
    if (model_instance.in_filename != NULL)
        free(model_instance.in_filename);
    if (model_instance.out_filename != NULL)
        free(model_instance.out_filename);
    if (model_instance.prefix != NULL)
        free(model_instance.prefix);
}
