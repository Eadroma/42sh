/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** env
*/

#include "shell.h"

uchar env_command(shell_t *shell)
{
    extern char **environ;

    for (size_t i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);
    return 1;
}