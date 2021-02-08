/*
** EPITECH PROJECT, 2020
** my_strincl
** File description:
** my_strincl
*/

#include <stdbool.h>
#include <string.h>

bool my_strincl(char const *str, char const *part)
{
    size_t i = 0;
    int len = strlen(str);

    if (len < strlen(part))
        return false;
    for (; str[i] && str[i] != part[0]; i++);
    if (i == len)
        return false;
    for (size_t j = 0; str[i] && part[j]; i++, j++)
        if (str[i] != part[j])
            return false;
    return true;
}