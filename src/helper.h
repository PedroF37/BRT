#ifndef _HELPER_H
#define _HELPER_H


#include "operations.h"
#include "args.h"

/* Cuida de mostrar como usar o programa */
void print_usage();


/* Renomeia e retorna true ou false
 * para se foi ou não renomeado */
bool is_renamed(char *pathname, char *new_name);


/* Cuida de verificar que se tem extensão e se são iguais */
bool has_same_extension(char *pathname, char *extension);


/* Cuida de remover o . de ".pdf", etc, caso tenha digitado . */
char *remove_dot_from_extension(char *extension);


/* Cuida de chamar a operação apropriada */
Result call_operation(Operation operation,
    char *pathname, char **argv);


/* Cuida de varrer o diretório alvo recursivamente */
void search_directory(Operation operation,
    char *directory, char **argv);

#endif
