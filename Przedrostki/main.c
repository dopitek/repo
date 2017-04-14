#include "core/menu.h"
#include "core/core.h"

int main(int argc, char** argv)
{
    model model_t = menu(argc, argv);
    if (model_t.valid)
    {
       process(model_t);
    }
    return 0;
}
