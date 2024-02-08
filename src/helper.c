#include "brt.h"
#include "helper.h"


void print_usage()
{
    printf("\nBulk Renaming Tool - Renomeação em Massa de Arquivos\n\n"
           "Uso: brt Diretório OPÇÃO ALVO\n\n"
           "OPÇÕES:\n"
           "  -a, --add            Alvo Adicionar\n"
           "  -i, --insert         Alvo Inserir\n"
           "  -ae, --add-ext       Alvo Adicionar Extensão\n"
           "  -ie, --insert-ext    Alvo Inserir Extensão\n"
           "  -r, --replace        Alvo Antigo Novo\n"
           "  -re, --replace-ext   Alvo Antigo Novo Extensão\n"
           "  -d, --delete         Alvo Deletar\n"
           "  -de, --delete-ext    Alvo Deletar Extensão\n\n"
           "Todas as operações executadas são feitas usando recursão no diretório alvo\n\n"
           "Exemplos:\n\n"
           "  $ brt /home/usuario/Documentos -a curriculum -profissional\n"
           "     Adiciona '-profissional' depois de 'curriculum', a todos os arquivos em Documentos com 'curriculum' no nome\n"
           "  $ brt ~/Imagens -i Férias-de-Verão Minhas-\n"
           "     Insere antes de 'Férias-de-Verão' 'Minhas-' em todos os arquivos em Imagens com 'Férias-de-Verão' no nome\n"
           "  $ brt ~/Videos --add-ext Aniversário -2023 mp4\n"
           "     Adiciona '-2023' depois de 'Aniversário' em todos os arquivos em Videos com 'Aniversário' no nome, mas apenas os que têm a extensão 'mp4'\n"
           "  $ brt ~/Videos -ie Aniversário Minha-Festa-de- mkv\n"
           "     Insere antes de 'Aniversário' 'Minha-Festa-de-' em todos os arquivos em Videos com 'Aniversário' no nome, mas apenas os que têm a extensão 'mkv'\n"
           "  $ brt /home/usuario/Imagens --replace Natal _2021 _2022\n"
           "     Substitui em Imagens '_2021' por '_2022' em todos os arquivos com 'Natal' no nome\n"
           "  $ brt ~/Imagens -re Natal _2021 _2022 jpg\n"
           "     Sustitui em Imagens '_2021' por '_2022' em todos os arquivos com 'Natal' no nome, mas apenas os que têm a extensão 'jpg'\n"
           "  $ brt ~/Documentos -d curriculum -profissional\n"
           "     Deleta em Documentos '-profissional' em todos os arquivos com 'curriculum' no nome\n"
           "  $ brt ~/Documentos --delete-ext curriculum -profissional docx\n"
           "     Deleta em Documentos '-profissional' em todos os arquivos com 'curriculum' no nome mas apenas os que têm a extensão 'docx'\n\n");
    return;
}


bool is_renamed(char *pathname, char *new_name)
{
    if (rename(pathname, new_name) != 0)
    {
        return(false);
    }

    return(true);
}


bool has_same_extension(char *pathname, char *extension)
{
    char *ext;
    if ((ext = has_extension(pathname)) == NULL)
    {
        return(false);
    }

    if (strcmp(ext, extension) != 0)
    {
        return(false);
    }

    return(true);
}


char *remove_dot_from_extension(char *extension)
{
    char *new_ext;
    if ((new_ext = strrchr(extension, '.')) != NULL)
    {
        return(new_ext + 1);
    }

    return(extension);
}


Result call_operation(Operation operation,
    char *pathname, char **argv)
{
    Result result;
    char *ext = NULL;
    switch (operation)
    {
        case ADD:
            result = add_in_filename(pathname,
                *argv, *(argv + 1));
            break;

        case INSERT:
            result = insert_in_filename(pathname,
                *(argv + 1));
            break;

        case ADD_EXT:
            ext = remove_dot_from_extension(*(argv + 2));
            result = add_in_filename_ext(pathname,
                *argv, *(argv + 1), ext);
            break;

        case INSERT_EXT:
            ext = remove_dot_from_extension(*(argv + 2));
            result = insert_in_filename_ext(pathname,
                *(argv + 1) ,ext);
            break;

        case REPLACE:
            result = replace_in_filename(pathname,
                *(argv + 1), *(argv + 2));
            break;

        case REPLACE_EXT:
            ext = remove_dot_from_extension(*(argv + 3));
            result = replace_in_filename_ext(pathname,
                *(argv + 1), *(argv + 2), ext);
            break;

        case DELETE:
            result = delete_in_filename(pathname,
                *(argv + 1));
            break;

        case DELETE_EXT:
            ext = remove_dot_from_extension(*(argv + 2));
            result = delete_in_filename_ext(pathname,
                *(argv + 1), ext);
            break;
    }

    return(result);
}


void search_directory(Operation operation,
    char *directory, char **argv)
{
    DIR *dhandle;
    if ((dhandle = opendir(directory)) == NULL)
    {
        fprintf(stderr, "Erro abrindo %s\n", directory);
        closedir(dhandle);
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    Result result;
    while ((entry = readdir(dhandle)) != NULL)
    {
        char *fullpath;
        if ((fullpath = create_pathname(directory,
            entry->d_name)) == NULL)
        {
            fprintf(stderr, "Erro criando"
                " caminho para %s\n", entry->d_name);
            closedir(dhandle);
            exit(EXIT_FAILURE);
        }

        if (is_dot_directory(entry->d_name) ||
            is_simlink(fullpath))
        {
            continue;
        }

        if (is_directory(fullpath))
        {
            remove_last_char(fullpath, '/');
            search_directory(operation, fullpath, argv);
        }

        if (is_equal_name(basename(fullpath), *argv) == false)
        {
            continue;
        }

        if ((result = call_operation(operation,
            fullpath, argv)) != SUCCESS)
        {
            if (result == CONTINUE)
            {
                continue;
            }
            else
            {
                closedir(dhandle);
                exit(EXIT_FAILURE);
            }
        }

        free(fullpath);
    }

    closedir(dhandle);
}
