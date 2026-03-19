/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** free_array
*/

#include "shell.h"

/**
 * @brief Fully frees a NULL-terminated array of strings (char matrix).
 * 
 * Iterates through each string, frees it, and then frees the array pointer itself.
 * 
 * @param array The NULL-terminated array of strings to free.
 */
void free_array(char **array)
{
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}