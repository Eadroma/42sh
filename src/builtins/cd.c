/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** cd
*/

#include "shell.h"

uchar cd_command(shell_t *shell)
{
    list_args_t *list = shell->args;
    char *to_move = my_str_to_word_array(list->head->line, ' ')[1];
    char *alias[3] = {"~-", "HOME", "OLDPWD"};

    for (size_t i = 0; alias[i]; i++)
        if (alias[0][i] && my_strcmp(&alias[0][i], to_move))
            to_move = search_env(alias[i]);
    if (chdir(to_move) == -1)
        perror(to_move);
    return 0;
}