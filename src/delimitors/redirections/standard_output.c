/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** standard_output
*/

#include "shell.h"

/**
 * @brief Allocates an open writing or appending file descriptor depending on operator.
 * 
 * Adjust flags to accommodate append conditions dynamically.
 * 
 * @param shell Global state managing fd targeting struct variables.
 * @param filename File path location to connect mapping toward.
 * @return Descriptor connection offset ID.
 */
static uchar get_fd(shell_t *shell, char *filename)
{
    shell->fd = (my_strcmp(shell->args->head->line, ">")) ?
        open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR |
            S_IRGRP | S_IROTH) :
        open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR |
            S_IWUSR | S_IRGRP | S_IROTH);
    if (shell->fd == -1) {
        perror("open");
        shell->fd = STDOUT_FILENO;
        return 84;
    }
    return 0;
}

/**
 * @brief Maps native standard output descriptors to open file descriptors.
 * 
 * Addresses both `>` and `>>` output redirection handling logic.
 * 
 * @param shell The environment pipeline context object.
 * @param pos Sequence placement indication.
 * @return 0 post valid evaluation, 84 directly on descriptor open errors.
 */
uchar standard_output_redirection(shell_t *shell, bool2_t pos)
{
    char *filename = get_filename(shell);
    int save_stdout = dup(STDOUT_FILENO);

    if (redirections_error_management(shell, pos) || get_fd(shell, filename))
        return 84;
    my_dup(shell, STDOUT_FILENO);
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    reset_fd(shell, save_stdout, STDOUT_FILENO);
    return 0;
}