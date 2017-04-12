#include <stdio.h>
#include <stdlib.h>
#include "fileext.h"
#include "menu.h"

bool validateInput(model settings)
{
    bool result = true;
    if (settings.prefix == NULL)
    {
        printf("Prafix not provided\n");
        result = false;
    }
    if (settings.in_filename == NULL)
    {
        printf("Prafix not provided\n");
        result = false;
    }
    else
    {
        if (!fileExists(settings.in_filename))
        {
            printf("Prafix not provided\n");
            result = false;
        }
    }
    if (settings.out_filename == NULL)
    {
        printf("Prafix not provided\n");
        result = false;
    }
    else
    {
        if (!fileExists(settings.in_filename))
        {
            printf("Prafix not provided\n");
            result = false;
        }
    }
    return result;
}

model initialize(int argc, char ** argv)
{
    int i;
    model settings;

    for(i=1;i<argc;i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][i] == 'p' && i+1<argc)
                settings.prefix = argv[i+1];
            if (argv[i][i] == 'o' && i+1<argc)
                settings.out_filename = argv[i+1];
            if (argv[i][i] == 'i' && i+1<argc)
                settings.in_filename = argv[i+1];
        }
    }

    settings.valid = validateInput(settings);
    return settings;
}


