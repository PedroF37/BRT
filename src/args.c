#include "brt.h"
#include "args.h"
#include "helper.h"


void number_args(int argc, int args)
{
    if (argc != args)
    {
        print_usage();
        exit(EXIT_FAILURE);
    }

    return;
}


void map_operation(int argc, char **argv)
{
    Operation operation;
    char *directory = *argv++;
    char *operation_str = *argv++;
    remove_last_char(directory, '/');

    if (strcmp(operation_str, "-a") == 0 ||
        strcmp(operation_str, "--add") == 0)
    {
        number_args(argc, 2);
        operation = ADD;
    }
    else if (strcmp(operation_str, "-i") == 0 ||
        strcmp(operation_str, "--insert") == 0)
    {
        number_args(argc, 2);
        operation = INSERT;
    }
    else if (strcmp(operation_str, "-ae") == 0 ||
        strcmp(operation_str, "--add-ext") == 0)
    {
        number_args(argc, 3);
        operation = ADD_EXT;
    }
    else if (strcmp(operation_str, "-ie") == 0 ||
        strcmp(operation_str, "--insert-ext") == 0)
    {
        number_args(argc, 3);
        operation = INSERT_EXT;
    }
    else if (strcmp(operation_str, "-r") == 0 ||
        strcmp(operation_str, "--replace") == 0)
    {
        number_args(argc, 3);
        operation = REPLACE;
    }
    else if (strcmp(operation_str, "-re") == 0 ||
        strcmp(operation_str, "--replace-ext") == 0)
    {
        number_args(argc, 4);
        operation = REPLACE_EXT;
    }
    else if (strcmp(operation_str, "-d") == 0 ||
        strcmp(operation_str, "--delete") == 0)
    {
        number_args(argc, 2);
        operation = DELETE;
    }
    else if (strcmp(operation_str, "-de") == 0 ||
        strcmp(operation_str, "--delete-ext") == 0)
    {
        number_args(argc, 3);
        operation = DELETE_EXT;
    }
    else
    {
        print_usage();
        exit(EXIT_FAILURE);
    }

    search_directory(operation, directory, argv);
}
