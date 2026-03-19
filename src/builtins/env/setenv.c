/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** setenv
*/

#include "shell.h"

/**
 * @brief Validates if a string contains only alphanumeric characters.
 * 
 * Used primarily for validating environment variable names.
 * 
 * @param str The string to validate.
 * @return true if valid, false if invalid.
 */
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

/**
 * @brief Checks if a variable exists in the environment, updating it if found.
 * 
 * @param array Command line argument array where index 1 is value.
 * @param var_name The key to check.
 * @return true if it already existed (and was updated), false otherwise.
 */
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

/**
 * @brief Checks the arguments provided for the setenv command.
 * 
 * If no arguments are provided, defaults to running 'env'.
 * 
 * @param shell The main shell state.
 * @param array Parsed setenv arguments.
 * @return 1 on failure, 0 on proper execution path.
 */
static int check_args(shell_t *shell, char **array)
{
    if (my_array_len(array) == 1)
        return env_command(shell);
    return (!is_alphanumeric(array[1])) ? 1 : 0;
}

/**
 * @brief Executes the built-in 'setenv' command.
 * 
 * Appends a new variable to the environment or modifies an existing one.
 * 
 * @param shell The main shell state.
 * @return 1 on finishing (success or failure).
 */
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