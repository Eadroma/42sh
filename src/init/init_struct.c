/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** init_struct
*/

#include "shell.h"

static list_args_t *init_list(void)
{
    list_args_t *list = malloc(sizeof(list_args_t));

    if (!list)
        exit(84);
    list->index = 0;
    list->head = NULL;
    return list;
}

shell_t *init_shell(void)
{
    shell_t *shell = malloc(sizeof(shell_t));

    if (!shell)
        exit(84);
    shell->fd = STDOUT_FILENO;
    shell->args = init_list();
    shell->list_alias = init_alias_list();
    fill_alias(shell);
    return shell;
}