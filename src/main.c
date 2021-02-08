/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** main
*/

#include "shell.h"

static int display_help(void)
{
    printf("USAGE:\n\t./42sh\n");
    return 0;
}

int main(int ac, char **av)
{
    return (ac == 2 && my_strcmp(av[1], "-h")) ? display_help() : shell_loop();
}