#include "core/menu.h"
#include "core/core.h"

int main(int argc, char** argv)
{
    model model_instance = initialize_model();
    menu(argc, argv, &model_instance);
    if (model_instance.valid)
    {
       process(model_instance);
    }

    //read("test.txt", "m");
    return 0;
}
