/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strchr
*/

#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Finds the native total character length bounded by formatting rules.
 * 
 * Custom fallback implementation of standard strlen.
 * 
 * @param str Bounded evaluation string pointer subject.
 * @return Cumulative numerical character length.
 */
int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

/**
 * @brief Identifies shifting offset position targeting a fixed mapping char.
 * 
 * @param str Base target stream matrix pointer.
 * @param delim Comparison token.
 * @return Memory sequence offset mapping indicating targeted offset.
 */
char *my_strchr(char *str, char const delim)
{
    for (; *str && *str != delim; str++);
    return *str == delim ? str : NULL;
}