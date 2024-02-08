#ifndef _OPERATIONS_H
#define _OPERATIONS_H


/* O resultado da operação escolhida */
typedef enum OperationResult
{
    SUCCESS, CONTINUE, FAILURE
}
Result;


/* Cuida de adicionar no nome depois de target */
Result add_in_filename(char *pathname, char *target, char *addition);


/* Cuida de inserir no nome antes de target */
Result insert_in_filename(char *pathname, char *insert);


/* Cuida de adicionar no nome depois de target, filtrando por extensão*/
Result add_in_filename_ext(char *pathname, char *target,
    char *addition, char *extension);


/* Cuida de inserir no nome antes de target, filtrando por extensão*/
Result insert_in_filename_ext(char *pathname,
    char *insert, char *extension);


/* Cuida de substituir old_str por new_str nos
 * arquivos com target no nome */
Result replace_in_filename(char *pathname,
    char *old_str, char *new_str);


/* Cuida de substituir old_str por new_str nos
 * arquivos com target no nome, filtrando por extensão*/
Result replace_in_filename_ext(char *pathname,
    char *old_str, char *new_str, char *extension);


/* Cuida de deletar to_delete nos arquivos com target no nome */
Result delete_in_filename(char *pathname, char *to_delete);


/* Cuida de deletar to_delete nos arquivos com
 * target no nome, filtrando por extensão*/
Result delete_in_filename_ext(char *pathname,
    char *to_delete, char *extension);


#endif
