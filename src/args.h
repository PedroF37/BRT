#ifndef _ARGS_H
#define _ARGS_H


/* A operação de renomeação */
typedef enum OperationType
{
    ADD, INSERT, ADD_EXT,
    INSERT_EXT, REPLACE,
    REPLACE_EXT, DELETE,
    DELETE_EXT
}
Operation;


/* Cuida de garantir o número certo de argumentos */
void number_args(int argc, int args);


/* Cuida de mapear a operação a ser executada */
void map_operation(int argc, char **argv);


#endif
