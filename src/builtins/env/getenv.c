/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** getenv
*/

#include "shell.h"

static int check_key(char const *to_find, char *env)
{
    int res = 0;

    for (int i = 0; i != my_strlen(to_find); i++)
        if (to_find[i] == env[i])
            res++;
    return res == my_strlen(to_find);
}

char *search_env(char const *to_find)
{
    extern char **environ;

    for (int i = 0; environ[i]; i++)
        for (int j = 0; environ[i][j]; j++) {
            if (environ[i][j] == '=' && check_key(to_find, environ[i]))
                return (environ[i] + j + 1);
        }
    return NULL;
}

uchar getenv_command(shell_t *shell)
{

    printf("%s\n", search_env(my_str_to_word_array(shell->args->head->line, ' ')
        [1]));
    return 0;
}