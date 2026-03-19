/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** remove_first_word
*/

#include <unistd.h>

/**
 * @brief Increments a string pointer past its first delimiting boundary.
 * 
 * Non-destructive offset adjustment skipping the first "word".
 * 
 * @param str The original mapped string.
 * @param delim Bound definition char.
 * @return Offset pointer starting immediately after the identified delimiter.
 */
char *remove_first_word(char *str, char delim)
{
    size_t i = 0;

    for (; str[i] && str[i + 1] && str[i] != delim; i++);
    return str + i + 1;
}