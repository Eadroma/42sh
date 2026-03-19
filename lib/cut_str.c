/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** cut_str
*/

#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Slices a substring from a given string.
 * 
 * @param str The source string.
 * @param start The starting index (inclusive).
 * @param end The ending index (exclusive).
 * @return The allocated sliced substring, or NULL on failure.
 */
char *cut_str(char *str, int start, int end)
{
    char *new_str = malloc(sizeof(char) * (end - start + 1));

    if (!new_str)
        return NULL;
    for (size_t res = 0; (end - start) >= res; res++)
        new_str[res] = str[res + start];
    new_str[end - start] = '\0';
    return new_str;
}