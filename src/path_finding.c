/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** path_finding
*/

#include "shell.h"

static int check_key(char const *to_find, char *env)
{
    size_t res = 0;

    for (size_t i = 0; i != strlen(to_find); i++)
        if (to_find[i] == env[i])
            res++;
    return res == strlen(to_find);
}

char *search_in_env(char const *to_find)
{
    extern char **environ;

    for (size_t i = 0; environ[i]; i++)
        for (size_t j = 0; environ[i][j]; j++)
            if (environ[i][j] == '=' && check_key(to_find, environ[i]))
                return (environ[i] + j + 1);
    return NULL;
}
