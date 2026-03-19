/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** path_finding
*/

#include "shell.h"

/**
 * @brief Helper function to match an environment key exactly against a search key.
 * 
 * @param to_find The key string to search for (e.g., "PATH").
 * @param env A full environment string (e.g., "PATH=/usr/bin").
 * @return 1 if the key matches exactly at the beginning of env, 0 otherwise.
 */
static int check_key(char const *to_find, char *env)
{
    size_t res = 0;

    for (size_t i = 0; i != strlen(to_find); i++)
        if (to_find[i] == env[i])
            res++;
    return res == strlen(to_find);
}

/**
 * @brief Searches the global environment matrix for a specific variable key.
 * 
 * @param to_find The variable name to search for.
 * @return A pointer to the value part of the environment string, or NULL if not found.
 */
char *search_in_env(char const *to_find)
{
    extern char **environ;

    for (size_t i = 0; environ[i]; i++)
        for (size_t j = 0; environ[i][j]; j++)
            if (environ[i][j] == '=' && check_key(to_find, environ[i]))
                return (environ[i] + j + 1);
    return NULL;
}
