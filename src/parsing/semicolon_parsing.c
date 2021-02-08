/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** semicolon_parsing
*/

#include "shell.h"

char **semicolon_parsing(char *line)
{
    char **array = my_str_to_word_array(line, ';');

    for (size_t i = 0; array[i]; i++)
        array[i] = clean_str(array[i], ' ');
    return array;
}