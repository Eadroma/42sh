/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** init_alias
*/

#include "shell.h"

/**
 * @brief Allocates and initializes a new alias variable node.
 * 
 * @param array A split array representing the alias key and mapping.
 * @return Newly allocated alias_t node, or NULL on failure.
 */
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

/**
 * @brief Initializes the main tracking list used for aliases.
 * 
 * @return A new allocated list_alias_t pointer.
 */
list_alias_t *init_alias_list(void)
{
    list_alias_t *list = malloc(sizeof(list_alias_t));

    if (!list)
        return NULL;
    list->size = 0;
    list->head = NULL;
    return list;
}

