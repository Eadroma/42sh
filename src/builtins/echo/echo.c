/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** echo
*/

#include "shell.h"

static char *remove_backslashes(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\\')
            str = remove_char(str, i);
    return str;
}

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

static char *backslashes_management(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '\\')
            str = check_backslash(str, i);
    return str;
}

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
