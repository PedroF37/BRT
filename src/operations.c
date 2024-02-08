#include "brt.h"
#include "operations.h"
#include "helper.h"


Result add_in_filename(char *pathname,
    char *target, char *addition)
{
    char *new_name;
    if ((new_name = str_insert(pathname,
        target, addition)) == NULL)
    {
        return(FAILURE);
    }

    if (is_renamed(pathname,
        new_name) == false)
    {
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, new_name);

    free(new_name);
    return(SUCCESS);
}


Result insert_in_filename(char *pathname, char *insert)
{
    char *new_name;
    if ((new_name = insert_in_beginning(basename(
        pathname), insert)) == NULL)
    {
        return(FAILURE);
    }

    char *pathname_copy = duplicate(pathname);
    if (pathname_copy == NULL)
    {
        free(new_name);
        return(FAILURE);
    }

    char *full_new_name;
    if ((full_new_name = create_pathname(
        dirname(pathname_copy), new_name)) == NULL)
    {
        free(pathname_copy);
        free(new_name);
        return(FAILURE);
    }

    if (is_renamed(pathname,
        full_new_name) == false)
    {
        free(pathname_copy);
        free(full_new_name);
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, full_new_name);

    free(pathname_copy);
    free(full_new_name);
    free(new_name);
    return(SUCCESS);
}


Result add_in_filename_ext(char *pathname,
    char *target, char *addition, char *extension)
{
    if (has_same_extension(pathname,
        extension) == false)
    {
        return(CONTINUE);
    }

    char *new_name;
    if ((new_name = str_insert(pathname,
        target, addition)) == NULL)
    {
        return(FAILURE);
    }

    if (is_renamed(pathname, new_name) == false)
    {
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, new_name);

    free(new_name);
    return(SUCCESS);
}


Result insert_in_filename_ext(char *pathname,
    char *insert, char *extension)
{
    if (has_same_extension(pathname,
        extension) == false)
    {
        return(CONTINUE);
    }

    char *new_name;
    if ((new_name = insert_in_beginning(
        basename(pathname), insert)) == NULL)
    {
        return(FAILURE);
    }

    char *pathname_copy = duplicate(pathname);
    if (pathname_copy == NULL)
    {
        free(new_name);
        return(FAILURE);
    }

    char *full_new_name;
    if ((full_new_name = create_pathname(
        dirname(pathname_copy), new_name)) == NULL)
    {
        free(pathname_copy);
        free(new_name);
        return(FAILURE);
    }

    if (is_renamed(pathname,
        full_new_name) == false)
    {
        free(pathname_copy);
        free(full_new_name);
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, full_new_name);

    free(pathname_copy);
    free(full_new_name);
    free(new_name);
    return(SUCCESS);
}


Result replace_in_filename(char *pathname,
    char *old_str, char *new_str)
{
    char *new_name;
    if ((new_name = str_replace(pathname,
        old_str, new_str)) == NULL)
    {
        return(FAILURE);
    }

    if (is_renamed(pathname, new_name) == false)
    {
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, new_name);

    free(new_name);
    return(SUCCESS);
}


Result replace_in_filename_ext(char *pathname,
    char *old_str, char *new_str, char *extension)
{
    if (has_same_extension(pathname,
        extension) == false)
    {
        return(CONTINUE);
    }

    char *new_name;
    if ((new_name = str_replace(pathname,
        old_str, new_str)) == NULL)
    {
        return(FAILURE);
    }

    if (is_renamed(pathname, new_name) == false)
    {
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, new_name);

    free(new_name);
    return(SUCCESS);
}


Result delete_in_filename(char *pathname, char *to_delete)
{
    char *new_name;
    if ((new_name = str_remove(pathname,
        to_delete)) == NULL)
    {
        return(FAILURE);
    }

    if (is_renamed(pathname, new_name) == false)
    {
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, new_name);

    free(new_name);
    return(SUCCESS);
}


Result delete_in_filename_ext(char *pathname,
    char *to_delete, char *extension)
{
   if (has_same_extension(pathname,
        extension) == false)
   {
       return(CONTINUE);
   }

    char *new_name;
    if ((new_name = str_remove(pathname,
        to_delete)) == NULL)
    {
        return(FAILURE);
    }

    if (is_renamed(pathname, new_name) == false)
    {
        free(new_name);
        return(FAILURE);
    }

    printf("%s -->> %s\n", pathname, new_name);

    free(new_name);
    return(SUCCESS);
}
