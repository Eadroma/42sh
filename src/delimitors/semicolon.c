/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** semicolon
*/

#include "shell.h"

/**
 * @brief Basic error check ensuring a semicolon does not operate on an invalid block.
 * 
 * @param pos Sequence positional data.
 * @return 1 on failure, 0 on safe bounds.
 */
static uchar error_management(bool2_t pos)
{
    return (pos.is_first && pos.is_last) ? 1 : 0;
}

/**
 * @brief Explicitly forces the evaluation of the command immediately preceding a semicolon.
 * 
 * @param shell The main shell context block.
 */
static void exec_last_node(shell_t *shell)
{
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next->next;
}

/**
 * @brief Coordinates the evaluation mapping for the sequential `;` delimiter operator.
 * 
 * @param shell Main context holding current execution pointer rules.
 * @param pos Boundaries checking.
 * @return Static execution state constant (usually 0).
 */
uchar semicolon_delimitor(shell_t *shell, bool2_t pos)
{
    if (error_management(pos))
        return 0;
    exec_last_node(shell);
    builtins_loop(shell);
    return 0;
}