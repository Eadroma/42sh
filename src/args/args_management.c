/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** args_management
*/

#include "shell.h"

/**
 * @brief Allocates and initializes a new argument node.
 * 
 * @param array The command string to store in the node.
 * @param is_delim Boolean indicating if this node represents a delimiter.
 * @return Newly allocated args_t node pointer.
 */
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

/**
 * @brief Inserts an argument node at the end of a doubly linked circular list.
 * 
 * @param head Pointer to the head of the circular list.
 * @param node Pointer to the node to insert.
 */
void insert_node(args_t *head, args_t *node)
{
    head->prev->next = node;
    node->prev = head->prev;
    head->prev = node;
    node->next = head;
}

/**
 * @brief Appends a node to the general arguments list structure.
 * 
 * Initializes the list with the node if the list is empty, otherwise inserts it.
 * 
 * @param list The main list tracking structure.
 * @param node The node to append.
 * @return true if appended successfully, false if node is NULL.
 */
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

/**
 * @brief Removes and returns a node from the list based on its index.
 * 
 * @param list The list to remove from.
 * @param index The 0-based positional index of the node to pop.
 * @return The popped argument node pointer.
 */
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

/**
 * @brief Pops a specific node by reference from the doubly linked list.
 * 
 * @param list The list object containing the node tracking data.
 * @param node The actual node pointer to be detached.
 * @return The detached argument node pointer.
 */
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