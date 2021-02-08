/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** or
*/

#include "shell.h"

static uchar error_management(bool2_t pos)
{
    if (pos.is_first || pos.is_last) {
        printf("Invalid null command.\n");
        return 84;
    }
    return 0;
}

uchar or_delimitor(shell_t *shell, bool2_t pos)
{
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    return 1;
}
