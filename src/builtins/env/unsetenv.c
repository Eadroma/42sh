/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** unsetenv
*/

#include "shell.h"

static void remove_line_env(size_t i)
{
    extern char **environ;

    for (; environ[i + 1]; i++)
        environ[i] = environ[i + 1];
    environ[i] = NULL;
}

static void check_var_names(char *var_name)
{
    extern char **environ;

    for (size_t i = 0; environ[i]; i++)
        if (my_strincl(environ[i], my_strcat(var_name, "=")))
            return remove_line_env(i);
    printf("unsetenv : %s variable doesn't exists\n", var_name);
}

uchar unsetenv_command(shell_t *shell)
{
    char **array = my_str_to_word_array(shell->args->head->line, ' ');
    extern char **environ;

    if (!array[1]) {
        printf("unsetenv : Needs at least one argument\n");
        return 1;
    }
    for (size_t i = 1; array[i]; i++)
        check_var_names(array[i]);
    return 1;
}