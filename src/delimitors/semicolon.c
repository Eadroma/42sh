/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** semicolon
*/

#include "shell.h"

static uchar error_management(bool2_t pos)
{
    return (pos.is_first && pos.is_last) ? 1 : 0;
}

static void exec_last_node(shell_t *shell)
{
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next->next;
}

uchar semicolon_delimitor(shell_t *shell, bool2_t pos)
{
    if (error_management(pos))
        return 0;
    exec_last_node(shell);
    builtins_loop(shell);
    return 0;
}