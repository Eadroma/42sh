/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** reset_list
*/

#include "shell.h"

/**
 * @brief Displays the contents of the commands argument list linearly.
 * 
 * @param list The argument list structure to display.
 */
void display_list(list_args_t *list)
{
    args_t *args = list->head;

    for (size_t i = 0; i < list->index; i++) {
            printf("node[%ld]: %s\n", i, args->line);
        args = args->next;
    }
}

/**
 * @brief Resets an argument list by setting its head to NULL and index to 0.
 * 
 * Note: This does not free the internal nodes.
 * 
 * @param list The list structure to reset.
 * @return The reset list pointer.
 */
list_args_t *reset_list(list_args_t *list)
{
    list->head = NULL;
    list->index = 0;
    return list;
}