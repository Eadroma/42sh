/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** init_alias
*/

#include "shell.h"

alias_t *create_alias(char **array)
{
    alias_t *alias = malloc(sizeof(alias_t));

    if (!alias)
        return NULL;
    alias->alias = array;
    alias->next = NULL;
    alias->prev = NULL;
    return alias;
}

list_alias_t *init_alias_list(void)
{
    list_alias_t *list = malloc(sizeof(list_alias_t));

    if (!list)
        return NULL;
    list->size = 0;
    list->head = NULL;
    return list;
}

