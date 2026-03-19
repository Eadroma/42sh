/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** flags_echo
*/

#include "shell.h"

/**
 * @brief Verifies if a given string argument strictly acts as an echo flag.
 * 
 * @param str The argument string.
 * @return true if valid flag format, false otherwise.
 */
static bool is_a_flag(char *str)
{
    if (str[0] != '-')
        return false;
    for (int i = 1; str[i]; i++)
        if (str[i] != 'n' && str[i] != 'e' && str[i] != 'E')
            return false;
    return true;
}

/**
 * @brief Checks if a specific flag character is contained within a flag stack string.
 * 
 * @param str The full flag string (e.g., "-ne").
 * @param flag The specific char to look for.
 * @return true if found, false otherwise.
 */
static bool is_flag_present(char *str, char flag)
{
    for (int i = 1; str[i]; i++)
        if (str[i] == flag)
            return true;
    return false;
}

/**
 * @brief Extracts enabled flags from the argument array for the echo command.
 * 
 * @param array The parsed arguments array.
 * @return An allocated boolean array indicating [n_flag, e_flag, E_flag] status.
 */
bool *get_flags(char **array)
{
    bool *flags = malloc(sizeof(bool) * 3);

    if (!flags)
        exit(84);
    for (int i = 0; i < 3; i++)
        flags[i] = false;
    for (int i = 1; i < get_flags_strings_nb(array); i++) {
        flags[n_flag] = (is_flag_present(array[i], 'n')) ? true :
            flags[n_flag];
        flags[e_flag] = (is_flag_present(array[i], 'e')) ? true :
            flags[n_flag];
    }
    flags[E_flag] = (!flags[e_flag]) ? true : false;
    return flags;
}

/**
 * @brief Counts how many leading arguments in the array are formatted as echo flags.
 * 
 * @param array The parsed arguments array.
 * @return The index of the first non-flag argument.
 */
int get_flags_strings_nb(char **array)
{
    int i = 1;

    for (; array[i]; i++)
        if (!is_a_flag(array[i]))
            break;
    return i;
}