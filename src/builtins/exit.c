/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** exit
*/

#include "shell.h"

/**
 * @brief Executes the built-in 'exit' command.
 * 
 * Terminates the shell execution immediately.
 * 
 * @param shell The main shell state.
 * @return Does not return.
 */
uchar exit_command(shell_t *shell)
{
    (void)shell;
    exit(0);
}