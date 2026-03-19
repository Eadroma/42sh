/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** my_strcmp
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>

/**
 * @brief Strictly compares two strings for exact equality.
 * 
 * Custom safe comparison implementation.
 * 
 * @param a The first string to compare.
 * @param b The second string to compare against.
 * @return true if strings match exactly, false otherwise or if either is NULL.
 */
bool my_strcmp(char const *a, char const *b)
{
    if (!a || !b || strlen(a) != strlen(b))
        return false;
    for (int i = 0; a[i]; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

/**
 * @brief Measures the number of string elements in a NULL-terminated array.
 * 
 * @param array The string array matrix.
 * @return Count of populated strings within.
 */
int my_array_len(char **array)
{
    int i = 0;

    if (!array)
        return i;
    for (; array[i]; i++);
    return i;
}