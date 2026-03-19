/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** or
*/

#include "shell.h"

/**
 * @brief Flags positional sequence errors associated with the '||' OR operator.
 * 
 * @param pos Configuration status bounds tracking.
 * @return 84 upon null command sequence violation, 0 otherwise.
 */
static uchar error_management(bool2_t pos)
{
    if (pos.is_first || pos.is_last) {
        printf("Invalid null command.\n");
        return 84;
    }
    return 0;
}

/**
 * @brief Defines boolean skip logic when evaluating commands over the '||' delimiter.
 * 
 * @param shell Main state.
 * @param pos Structural tracking indicating boundaries.
 * @return 1 upon resolution.
 */
uchar or_delimitor(shell_t *shell, bool2_t pos)
{
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    return 1;
}
