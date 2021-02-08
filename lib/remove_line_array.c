/*
** EPITECH PROJECT, 2020
** remove line array
** File description:
** remove_line_array
*/

#include <stddef.h>
#include <stdbool.h>

bool my_strcmp(char const *a, char const *b);

void remove_line_array(char **array, int i)
{
    int res = i;

    if (!array)
        return;
    for (; array[res] && array[res + 1]; res++)
        array[res] = array[res + 1];
    if (res != i)
        array[res] = NULL;
}

char  **clean_array(char **array, char *str)
{
    for (int i = 0; array[i]; i++) {
        if (my_strcmp(array[i], str))
            remove_line_array(array, i);
    }
    return array;
}