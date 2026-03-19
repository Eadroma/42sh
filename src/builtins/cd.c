/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** cd
*/

#include "shell.h"

/**
 * @brief Executes the built-in 'cd' command to change the current directory.
 * 
 * Includes support for standard aliases like '~-' and basic path resolution.
 * 
 * @param shell The main shell state.
 * @return 0 on completion, regardless of success.
 */
uchar cd_command(shell_t *shell)
{
    list_args_t *list = shell->args;
    char *to_move = my_str_to_word_array(list->head->line, ' ')[1];

    if (!to_move || my_strcmp("~", to_move))
        to_move = search_env("HOME");
    else if (my_strcmp("-", to_move))
        to_move = search_env("OLDPWD");
    
    if (to_move && chdir(to_move) == -1)
        perror(to_move);
    return 0;
}