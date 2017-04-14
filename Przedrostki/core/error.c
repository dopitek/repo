#include "error.h"

message load_error_messages()
{
    message message_t =
    {
        "prefix_missing",
        "prefix_missing",
        "prefix_missing",
        "prefix_missing"


    };

    //sprintf() message_t.prefix_missing = "prefix_missing",
    //message_t.input_file_name_missing = "input_file_name_missing",
    //message_t.output_file_name_missing = "output_file_name_missing",
    //message_t.help = "help"

    return message_t;
}
