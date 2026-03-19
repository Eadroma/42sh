/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** main
*/

#include "shell.h"

/**
 * @brief Displays the help usage message for the shell.
 * 
 * @return Always returns 0.
 */
static int display_help(void)
{
    printf("USAGE:\n\t./42sh\n");
    return 0;
}

/**
 * @brief Main entry point for the 42sh shell program.
 * 
 * Handles command-line arguments and starts the shell loop or displays help.
 * 
 * @param ac The argument count.
 * @param av The argument vector.
 * @return Returns the exit status of the shell loop or 0 for help.
 */
int main(int ac, char **av)
{
    return (ac == 2 && my_strcmp(av[1], "-h")) ? display_help() : shell_loop();
}