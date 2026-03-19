/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** standard_input
*/

#include "shell.h"

/**
 * @brief Operator evaluator for the standard input redirection `<`.
 * 
 * Alters STDIN to securely pull direct from a referenced path descriptor, allowing commands 
 * to act natively as if input sourced locally.
 * 
 * @param shell Active internal state reference pointer.
 * @param pos Sequence boundary indicator parameter.
 * @return 0 upon successful command bridging.
 */
uchar simple_standard_input_redirection(shell_t *shell, bool2_t pos)
{
    char *filename = get_filename(shell);
    int saved_stdin = dup(STDIN_FILENO);

    if (redirections_error_management(shell, pos))
        return 84;
    my_dup(shell, STDIN_FILENO);
    shell->args->head = shell->args->head->prev;
    shell->args->head->next = shell->args->head->next->next->next;
    shell->args->head->line = my_strcat(shell->args->head->line,
        my_strcat(" ", filename));
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    reset_fd(shell, saved_stdin, STDIN_FILENO);
    return 0;
}