/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** standard_functions
*/

#include "shell.h"

/**
 * @brief Universal baseline handler checking input arguments formatting for redirs.
 * 
 * @param shell The environment command chain block.
 * @param pos Bound configuration limit.
 * @return Hardcoded to 0 currently representing skip/success context.
 */
uchar redirections_error_management(shell_t *shell, bool2_t pos)
{
    return 0;
}

/**
 * @brief Safely detaches the file name or descriptor tag right after a redirection operator.
 * 
 * Transforms tracking boundaries immediately to compensate parsing offset.
 * 
 * @param shell Shell environment configuration context.
 * @return Malloced string path / filename parsed.
 */
char *get_filename(shell_t *shell)
{
    char *line = remove_first_word(shell->args->head->next->line, ' ');
    char *filename = my_str_to_word_array(shell->args->head->next->line,
        ' ')[0];

    shell->args->head->next->line = line;
    return filename;
}
