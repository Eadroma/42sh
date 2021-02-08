/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** flags_echo
*/

#include "shell.h"

static bool is_a_flag(char *str)
{
    if (str[0] != '-')
        return false;
    for (int i = 1; str[i]; i++)
        if (str[i] != 'n' && str[i] != 'e' && str[i] != 'E')
            return false;
    return true;
}

static bool is_flag_present(char *str, char flag)
{
    for (int i = 1; str[i]; i++)
        if (str[i] == flag)
            return true;
    return false;
}

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

int get_flags_strings_nb(char **array)
{
    int i = 1;

    for (; array[i]; i++)
        if (!is_a_flag(array[i]))
            break;
    return i;
}