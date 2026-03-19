/*
** EPITECH PROJECT, 2020
** my realloc array
** File description:
** my realloc array
*/

#include <stdlib.h>
#include <string.h>

/**
 * @brief Re-allocates a null-terminated string array with a new size.
 * 
 * Duplicates internal strings safely without double-free risks.
 * 
 * @param array Source string array.
 * @param size The new aggregate size boundary target.
 * @return The newly allocated padded array, or NULL on failure.
 */
char **my_realloc_array(char **array, int size)
{
    int i = 0;
    char **new = malloc(sizeof(char *) * (size + 1));

    if (!new)
        return NULL;
    for (; array[i] && i < size; i++) {
        new[i] = malloc(sizeof(char) * (strlen(array[i]) + 1));
        if (!new[i])
            return NULL;
        new[i] = array[i];
    }
    for (; i <= size; i++)
        new[i] = NULL;
    return new;
}
