/*
** EPITECH PROJECT, 2020
** my_concat_str
** File description:
** concat_str
*/

#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocates and concatenates two string sequences iteratively.
 * 
 * Custom safe non-destructive alternative to core strcat.
 * 
 * @param s1 Left-side source sequence prefix.
 * @param s2 Right-side source sequence suffix.
 * @return New allocated merged buffer string pointer.
 */
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
