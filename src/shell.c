/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** shell
*/

#include <ncurses.h>
#include "shell.h"

/**
 * @brief Reads a line of input from the terminal.
 * 
 * Displays the shell prompt, allocates memory, and reads stdin until a newline.
 * If EOF is reached, it automatically exits.
 * 
 * @return Allocated string containing the command line input, with trailing newline removed.
 */
static char *read_term(void)
{
    char *line = NULL;
    size_t len = 0;

    display_prompt();
    if (getline(&line, &len, stdin) == -1)
        exit(0);
    return end_str(line, '\n');
}

/**
 * @brief Processes one full cycle of reading user input and checking for exit.
 * 
 * @param shell The current shell state structure.
 * @return true if the shell should terminate, false otherwise.
 */
static bool is_end(shell_t *shell)
{
    if ((shell->command_line = read_term())) {
        shell->args = reset_list(shell->args);
        get_input(shell);
    }
    return false;
}

/**
 * @brief Main continuous execution loop for the shell.
 * 
 * Initializes the shell structures and continually processes user input,
 * adds commands to history, and evaluates delimiters.
 * 
 * @return Default exit status (typically 0).
 */
int shell_loop(void)
{
    shell_t *shell = init_shell();

    while (!is_end(shell)) {
        add_to_history(shell);
        get_delim(shell);
    }
    return 0;
}