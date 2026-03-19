/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** remove_char
*/

/**
 * @brief Removes a single character directly from a string in-place by index.
 * 
 * Shifts the rest of the string backwards to overwrite it.
 * 
 * @param str The modifiable string.
 * @param i Index of the character targeted for removal.
 * @return The manipulated string pointer.
 */
char *remove_char(char *str, int i)
{
    for (; str[i + 1]; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    return str;
}