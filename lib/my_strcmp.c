/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** my_strcmp
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>

bool my_strcmp(char const *a, char const *b)
{
    if (!a || !b || strlen(a) != strlen(b))
        return false;
    for (int i = 0; a[i]; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int my_array_len(char **array)
{
    int i = 0;

    if (!array)
        return i;
    for (; array[i]; i++);
    return i;
}