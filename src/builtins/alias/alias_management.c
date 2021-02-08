/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** alias_management
*/

#include "shell.h"

void insert_alias(alias_t *head, alias_t *node)
{
    head->prev->next = node;
    node->prev = head->prev;
    head->prev = node;
    node->next = head;
}

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

void modify_alias(alias_t *node, char **array)
{
    if (!node)
        return;
    node->alias = array;
}

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