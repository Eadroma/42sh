/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** alias_management
*/

#include "shell.h"

/**
 * @brief Inserts an alias node at the tail of the circular doubly linked list.
 * 
 * @param head The list's designated head node.
 * @param node The new alias node to insert.
 */
void insert_alias(alias_t *head, alias_t *node)
{
    head->prev->next = node;
    node->prev = head->prev;
    head->prev = node;
    node->next = head;
}

/**
 * @brief Appends a new alias to the shell's alias list.
 * 
 * Initializes the list if it is currently empty, else inserts normally.
 * 
 * @param list The alias tracking list structure.
 * @param node The alias node to append.
 * @return true if appended successfully, false if node is NULL.
 */
bool append_alias(list_alias_t *list, alias_t *node)
{
    if (!node)
        return false;
    list->size++;
    if (list->head)
        insert_alias(list->head, node);
    else {
        list->head = node;
        node->prev = node;
        node->next = node;
    }
    return true;
}

/**
 * @brief Replaces the aliased command array within an existing alias node.
 * 
 * @param node The node to modify.
 * @param array The new command array to replace the old alias.
 */
void modify_alias(alias_t *node, char **array)
{
    if (!node)
        return;
    node->alias = array;
}

/**
 * @brief Validates if a command maps to an existing alias and substituting it.
 * 
 * Reads the .alias file directly to search for an active translation.
 * 
 * @param cmd_name The raw command name string.
 * @return The associated alias string if found, otherwise returns the original input.
 */
char *check_alias(char *cmd_name)
{
    char **file = read_alias_file(fopen(".alias", "r"));

    if (!file)
        return cmd_name;
    for (size_t i = 0; file[i]; i++)
        if (my_strincl(file[i], cmd_name)) {
            return my_str_to_word_array(file[i], ' ')[1];
        }
    return cmd_name;
}