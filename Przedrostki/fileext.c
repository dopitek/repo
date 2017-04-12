#include <stdio.h>
#include "fileext.h"

int fileExists(const char *fileName)
{
    FILE *file;
    if ((file = fopen(fileName, "r")) != NULL)
    {
        fclose(file);
        return 1;
    }
    return 0;
}
