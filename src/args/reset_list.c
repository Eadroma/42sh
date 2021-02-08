/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** reset_list
*/

#include "shell.h"

void display_list(list_args_t *list)
{
    args_t *args = list->head;

    for (size_t i = 0; i < list->index; i++) {
            printf("node[%ld]: %s\n", i, args->line);
        args = args->next;
    }
}

list_args_t *reset_list(list_args_t *list)
{
    list->head = NULL;
    list->index = 0;
    return list;
}