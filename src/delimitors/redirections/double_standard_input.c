/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** double_standard_input
*/

#include "shell.h"

static uchar write_in_file(char *filename, char *line)
{
    int fd = open(filename, O_WRONLY | O_APPEND);

    if (fd == -1)
        return 84;
    write(fd, line, strlen(line));
    write(fd, "\n", 1);
    close(fd);
    return 0;
}

static uchar redirect_loop(shell_t *shell, char *filename)
{
    char *delim = get_filename(shell);
    char *line = NULL;
    FILE *stream = fopen(filename, "a");
    size_t len = 0;

    if (!stream)
        return 84;
    while (1) {
        printf("> ");
        if (getline(&line, &len, stdin) == -1)
            return 84;
        line = end_str(line, '\n');
        if (my_strcmp(line, delim))
            break;
        write_in_file(filename, line);
    }
    fclose(stream);
    return 0;
}

uchar double_standard_input_redirection(shell_t *shell, bool2_t pos)
{
    char filename[10] = ".redirect";
    int saved_stdin = dup(STDIN_FILENO);

    if (redirections_error_management(shell, pos) ||
        redirect_loop(shell, filename) || (shell->fd = open(filename, O_RDONLY))
            == -1) {
        return 84;
    }
    my_dup(shell, STDIN_FILENO);
    shell->args->head = shell->args->head->prev;
    shell->args->head->next = shell->args->head->next->next->next;
    shell->args->head->line = my_strcat(shell->args->head->line,
        my_strcat(" ", filename));
    builtins_loop(shell);
    shell->args->head = shell->args->head->next;
    reset_fd(shell, saved_stdin, STDIN_FILENO);
    remove(filename);
    return 0;
}