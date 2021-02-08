/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strchr
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

char *my_strchr(char *str, char const delim)
{
    for (; *str && *str != delim; str++);
    return *str == delim ? str : NULL;
}