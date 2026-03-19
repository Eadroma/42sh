/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** getenv
*/

#include "shell.h"

/**
 * @brief Checks if an environment key starts with a specific search string.
 * 
 * @param to_find The string key to find.
 * @param env The environment variable string.
 * @return 1 if found matching length, 0 otherwise.
 */
static int check_key(char const *to_find, char *env)
{
    int len = my_strlen(to_find);
    int res = 0;

    for (int i = 0; i < len; i++)
        if (to_find[i] == env[i])
            res++;
    return (res == len && env[len] == '=');
}

/**
 * @brief Searches for an environment variable by name.
 * 
 * @param to_find The environment variable key.
 * @return Pointer within the environment string, or NULL if missing.
 */
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

/**
 * @brief Executes a command to retrieve and print a specific environment variable.
 * 
 * @param shell The main shell state.
 * @return 0 upon successful printing.
 */
uchar getenv_command(shell_t *shell)
{

    printf("%s\n", search_env(my_str_to_word_array(shell->args->head->line, ' ')
        [1]));
    return 0;
}