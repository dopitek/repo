#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

typedef struct message {
    char prefix_missing[32];
    char input_file_name_missing[32];
    char input_file_missing[32];
    char output_file_name_missing[32];
    char output_file_missing[32];
    char help[32];
} message;

message load_error_messages();


#endif // ERROR_H_INCLUDED
