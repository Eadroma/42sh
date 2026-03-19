/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** semicolon_parsing
*/

#include "shell.h"

/**
 * @brief Extracts separated evaluation lines chained sequentially via semicolons.
 * 
 * Translates an inline chaining buffer into distinctly split command strings.
 * 
 * @param line The overarching command line payload.
 * @return Array matrix of individual complete commands ready for local extraction.
 */
char **semicolon_parsing(char *line)
{
    char **array = my_str_to_word_array(line, ';');

    for (size_t i = 0; array[i]; i++)
        array[i] = clean_str(array[i], ' ');
    return array;
}