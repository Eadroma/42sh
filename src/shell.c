/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** shell
*/

#include <ncurses.h>
#include "shell.h"

static char *read_term(void)
{
    char *line = NULL;
    size_t len = 0;

    display_prompt();
    if (getline(&line, &len, stdin) == -1)
        exit(0);
    return end_str(line, '\n');
}

static bool is_end(shell_t *shell)
{
    if ((shell->command_line = read_term())) {
        shell->args = reset_list(shell->args);
        get_input(shell);
    }
    return false;
}

int shell_loop(void)
{
    shell_t *shell = init_shell();

    while (!is_end(shell)) {
        add_to_history(shell);
        get_delim(shell);
    }
    return 0;
}