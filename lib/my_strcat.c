/*
** EPITECH PROJECT, 2020
** my_concat_str
** File description:
** concat_str
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char const *s1, char const *s2)
{
    int len = strlen(s1) + strlen(s2);
    char *dest = malloc(sizeof(char) * len + 1);
    int i = 0;

    if (!dest)
        return NULL;
    for (; s1[i]; i++)
        dest[i] = s1[i];
    for (int j = 0; s2[j]; j++, i++)
        dest[i] = s2[j];
    dest[len] = '\0';
    return dest;
}
