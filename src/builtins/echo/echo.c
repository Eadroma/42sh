/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** echo
*/

#include "shell.h"

/**
 * @brief Strips literal backslash characters from a string.
 * 
 * @param str The string to modify.
 * @return The modified string pointer.
 */
static char *remove_backslashes(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\\')
            str = remove_char(str, i);
    return str;
}

/**
 * @brief Converts escaped character sequences into their actual character equivalents.
 * 
 * Resolves standard escape sequences such as \\n or \\t in-place.
 * 
 * @param str The string being processed.
 * @param i The index of the backslash character.
 * @return The modified string pointer.
 */
static char *check_backslash(char *str, int i)
{
    char next[9] = {'\\', 'a', 'b', 'e', 'f', 'n', 'r', 't', 'v'};
    char new[9] = {'\\', '\a', '\b', '\e', '\f', '\n', '\r', '\t', '\v'};

    for (int j = 0; j < 9; j++) {
        if (str[i + 1] && str[i + 1] == next[j]) {
            str[i] = new[j];
            i++;
            break;
        }
    }
    str = remove_char(str, i);
    return str;
}

/**
 * @brief Manages backslash interpretation across an entire string.
 * 
 * @param str The string containing potential escape sequences.
 * @return The fully interpreted string pointer.
 */
static char *backslashes_management(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\\')
            str = check_backslash(str, i);
    return str;
}

/**
 * @brief Applies the formatting rules defined by echo flags (e.g., -n, -e, -E).
 * 
 * @param line The raw command line used to parse flags.
 * @param str The accumulated string to process.
 * @return The formatted string ready for output.
 */
static char *check_flags(char *line, char *str)
{
    bool *flags = get_flags(my_str_to_word_array(line, ' '));

    if (flags[n_flag])
        str[strlen(str) - 1] = '\0';
    if (flags[E_flag])
        str = remove_backslashes(str);
    if (flags[e_flag])
        str = backslashes_management(str);
    return str;
}

/**
 * @brief Executes the built-in 'echo' command.
 * 
 * Prints the provided arguments adhering to requested formatting flags.
 * 
 * @param shell The main shell state.
 * @return 1 upon successful execution.
 */
uchar echo_command(shell_t *shell)
{
    char **array = my_str_to_word_array(shell->args->head->line, ' ');
    char *str = malloc(sizeof(char));

    if (!str)
        exit(84);
    str[0] = '\0';
    for (int i = get_flags_strings_nb(array); array[i]; i++)
        str = my_strcat(str, my_strcat(array[i], " "));
    str[strlen(str) -1] = '\n';
    str = check_flags(shell->args->head->line, str);
    printf("%s", str);
    return 1;
}
