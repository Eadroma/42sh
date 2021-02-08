/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** remove_first_word
*/

#include <unistd.h>

char *remove_first_word(char *str, char delim)
{
    size_t i = 0;

    for (; str[i] && str[i + 1] && str[i] != delim; i++);
    return str + i + 1;
}