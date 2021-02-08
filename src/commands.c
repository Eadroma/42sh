/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** commands
*/

#include "shell.h"

uchar builtins_loop(shell_t *shell)
{
    char *cmd_name = check_alias(my_str_to_word_array(shell->args->head->line,
        ' ')[0]);

    for (size_t i = 0; i < COMMANDS_COUNT; i++)
        if (my_strcmp(cmd_name, COMMANDS[i].command_name))
            return COMMANDS[i].handler(shell);
    return basic_command(shell);
}

static uchar delimitors_loop(char *cmd_name, shell_t *shell, bool2_t pos)
{
    for (size_t i = 0; i < DELIMITORS_COUNT; i++)
        if (my_strcmp(cmd_name, DELIMITORS[i].delimitor))
            return DELIMITORS[i].handler(shell, pos);
    return 0;
}

uchar get_delim(shell_t *shell)
{
    char *cmd_name = NULL;
    args_t *first = shell->args->head;

    if (!shell->command_line || strlen(shell->command_line) < 2)
        return 84;
    for (size_t i = 0; i < shell->args->index; i++) {
        cmd_name = *my_str_to_word_array(shell->args->head->line, ' ');
        if (shell->args->head->is_delim)
            return delimitors_loop(cmd_name, shell,
                (bool2_t){first == shell->args->head,
                first == shell->args->head->prev});
        shell->args->head = shell->args->head->next;
    }
    builtins_loop(shell);
    return 0;
}