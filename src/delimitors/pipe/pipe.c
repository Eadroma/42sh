/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** pipe
*/

#include "shell.h"

/**
 * @brief Handles error conditions specific to the setup of pipe descriptors.
 * 
 * @param pos Current sequence boundary details.
 * @param pipefd The pointer to the pipe file descriptors array.
 * @return 84 on invalid command or pipe creation failure, 0 otherwise.
 */
static uchar error_management(bool2_t pos, int *pipefd)
{
    if (pos.is_first || pos.is_last) {
        printf("Invalid null command.\n");
        return 84;
    }
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 84;
    }
    return 0;
}

/**
 * @brief Adjusts the current shell's file descriptors to leverage pipes.
 * 
 * @param shell The main shell state.
 * @param to_dup The pipe endpoint fd to store/use.
 * @param to_close The remaining pipe endpoint to discard.
 */
static void prepare_to_dup(shell_t *shell, int to_dup, int to_close)
{
    close(to_close);
    shell->fd = to_dup;
}

/**
 * @brief Main evaluation routine for the pipe `|` operator.
 * 
 * Employs a temporary `.pipe` file to route standard output of the first
 * command into the standard input of the subsequent command.
 * 
 * @param shell The main shell state representation.
 * @param pos Command block bound tracking.
 * @return Pipeline exit status codes.
 */
uchar my_pipe(shell_t *shell, bool2_t pos)
{
    char filename[6] = ".pipe";
    int saved_stdin = dup(STDIN_FILENO);
    int saved_stdout = dup(STDOUT_FILENO);

    remove(filename);
    if ((shell->fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR |
        S_IRGRP | S_IROTH)) == -1)
        return 84;
    my_dup(shell, STDOUT_FILENO);
    shell->args->head = shell->args->head->prev;
    builtins_loop(shell);
    reset_fd(shell, saved_stdout, STDOUT_FILENO);
    if ((shell->fd = open(filename, O_RDONLY)) == -1) {
        perror(filename);
        return 84;
    }
    my_dup(shell, STDIN_FILENO);
    shell->args->head = shell->args->head->next->next;
    builtins_loop(shell);
    return reset_fd(shell, saved_stdin, STDIN_FILENO);
}