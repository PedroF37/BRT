#include "brt.h"
#include "helper.h"
#include "args.h"


#define ARG_MIN 5
#define ARG_MAX 7


int main(int argc, char **argv)
{
    if (argc < ARG_MIN || argc > ARG_MAX)
    {
        print_usage();
        return(EXIT_FAILURE);
    }

    if (!is_valid_directory(*(argv + 1)))
    {
        fprintf(stderr, "Diretório %s é inválido ou"
            " você não tem permissões\n", *(argv + 1));
        return(EXIT_FAILURE);
    }

    argv++;
    map_operation(argc - 3, argv);
    return(EXIT_SUCCESS);
}
