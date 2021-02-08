/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** standard_functions
*/

#include "shell.h"

uchar redirections_error_management(shell_t *shell, bool2_t pos)
{
    return 0;
}

char *get_filename(shell_t *shell)
{
    char *line = remove_first_word(shell->args->head->next->line, ' ');
    char *filename = my_str_to_word_array(shell->args->head->next->line,
        ' ')[0];

    shell->args->head->next->line = line;
    return filename;
}
