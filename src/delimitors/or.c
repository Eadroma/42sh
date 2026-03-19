/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** or
*/

#include "shell.h"

/**
 * @brief Defines boolean skip logic when evaluating commands over the '||' delimiter.
 * 
 * @param shell Main state.
 * @param pos Structural tracking indicating boundaries.
 * @return 1 upon resolution.
 */
uchar or_delimitor(shell_t *shell, bool2_t pos)
{
    (void)pos;
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    return 1;
}
