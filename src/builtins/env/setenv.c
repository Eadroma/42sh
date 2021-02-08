/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** setenv
*/

#include "shell.h"

static bool is_alphanumeric(char const *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9')) {
            printf("setenv: Variable name must contain only alphanumeric \
characters.\n");
            return false;
        }
    return true;
}

static bool var_already_exists(char **array, char const *var_name)
{
    extern char **environ;

    for (size_t i = 0; environ[i]; i++) {
        if (my_strincl(environ[i], var_name)) {
            environ[i] = my_strcat(var_name, array[1]);
            return true;
        }
    }
    return false;
}

static int check_args(shell_t *shell, char **array)
{
    if (my_array_len(array) == 1)
        return env_command(shell);
    return (!is_alphanumeric(array[1])) ? 1 : 0;
}

uchar setenv_command(shell_t *shell)
{
    char **array = my_str_to_word_array(shell->args->head->line, ' ');
    extern char **environ;
    int env_len = my_array_len(environ);

    if (check_args(shell, array) ||
        var_already_exists(array, my_strcat(array[1], "=")))
        return 1;
    if (!my_realloc_array(environ, env_len + 1))
        exit(84);
    environ[env_len] = (array[2]) ?
        my_strcat(my_strcat(array[1], "="), array[2]) :
        my_strcat(array[1], "=");
    environ[env_len + 1] = NULL;
    return 1;
}