/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** end_str
*/

#include <unistd.h>

char *end_str(char *str, char delim)
{
    for (size_t i = 0; str[i]; i++)
        str[i] = (str[i] == delim) ? '\0' : str[i];
    return str;
}