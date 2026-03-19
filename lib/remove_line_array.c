/*
** EPITECH PROJECT, 2020
** remove line array
** File description:
** remove_line_array
*/

#include <stddef.h>
#include <stdbool.h>

bool my_strcmp(char const *a, char const *b);

/**
 * @brief Erases a designated row line array pointer within a string matrix in-place.
 * 
 * Cascades following array members backwards to close the empty gap.
 * 
 * @param array Working 2D struct allocation block.
 * @param i Targeting line reference index height.
 */
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

/**
 * @brief Sweeps over an entire array removing any exact string matches automatically.
 * 
 * @param array Matrix configuration setup to search inside.
 * @param str Target exact inclusion string constraint filtering against.
 * @return Cleaned matrix array with removed matches.
 */
char  **clean_array(char **array, char *str)
{
    for (int i = 0; array[i]; i++) {
        if (my_strcmp(array[i], str))
            remove_line_array(array, i);
    }
    return array;
}