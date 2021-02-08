/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** my_dup
*/

#include <fcntl.h>
#include <unistd.h>
#include "shell.h"

uchar my_dup(shell_t *shell, int fd)
{
    if (dup2(shell->fd, fd) == -1) {
        perror("dup2");
        return 84;
    }
    return 0;
}

uchar reset_fd(shell_t *shell, int save, int fd)
{
    if (dup2(save, fd) == -1) {
        perror("dup2");
        return;
    };
    close(save);
    return 0;
}