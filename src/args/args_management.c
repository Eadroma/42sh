/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** args_management
*/

#include "shell.h"

args_t *create_node(char *array, bool is_delim)
{
    args_t *args = malloc(sizeof(args_t));

    if (!args)
        exit(84);
    args->line = clean_cmd_line(array);
    args->is_delim = is_delim;
    args->prev = NULL;
    args->next = NULL;
    return args;
}

void insert_node(args_t *head, args_t *node)
{
    head->prev->next = node;
    node->prev = head->prev;
    head->prev = node;
    node->next = head;
}

bool append_node(list_args_t *list, args_t *node)
{
    if (!node)
        return false;
    list->index++;
    if (list->head)
        insert_node(list->head, node);
    else {
        list->head = node;
        node->prev = node;
        node->next = node;
    }
    return true;
}

args_t *pop_index_node(list_args_t *list, int index)
{
    args_t *node = list->head;

    for (int i = 0; i < index; i++)
        node = node->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    list->index--;
    return node;
}

args_t *pop_node(list_args_t *list, args_t *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    list->index--;
    if (!list->index)
        list->head = NULL;
    if (node == list->head) {
        list->head->prev->next = list->head->next;
        list->head = list->head->next;
    }
    return node;
}