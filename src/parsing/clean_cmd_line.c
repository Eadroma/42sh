/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** clean_cmd_line
*/

#include "shell.h"

char *clean_cmd_line(char *line)
{
    for (size_t i = 0; line[i]; i++)
        line[i] = (line[i] == '\n') ? '\0' : line[i];
    for (size_t i = 0; line[i]; i++)
        line[i] = (line[i] == '\t') ? ' ' : line[i];
    for (size_t i = 0; line[i]; i++) {
        if (line[i + 1] && line[i] == ' ' && line[i + 1] == ' ') {
            line = remove_char(line, i);
            i--;
        }
    }
    return line;
}