/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** and
*/

#include "shell.h"

/**
 * @brief Handles formatting sequence errors relating to the '&&' operator.
 * 
 * @param pos The relative structural positioning parameters.
 * @return 84 on invalid conditions, 0 otherwise.
 */
static uchar error_management(bool2_t pos)
{
    if (pos.is_first && pos.is_last)
        return 84;
    if (pos.is_last) {
        printf("Invalid null command.\n");
        return 84;
    }
    return 0;
}

/**
 * @brief Handles logic execution surrounding the '&&' logical AND delimiter.
 * 
 * @param shell The main shell state.
 * @param pos Sequence information regarding the delim.
 * @return 1 on resolving AND behavior logic.
 */
uchar and_delimitor(shell_t *shell, bool2_t pos)
{
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next->next;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    return 1;
}
