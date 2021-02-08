/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** my exec
*/

#include "shell.h"

uchar my_exec(args_t *args)
{
    extern char **environ;
    char **path = my_str_to_word_array(search_in_env("PATH="), ':');
    char **array = my_str_to_word_array(args->line, ' ');
    char *cmd_name = my_strcat("/", check_alias(my_str_to_word_array(args->line,
        ' ')[0]));

    if (!path)
        return 1;
    for (int i = 0; path[i]; i++)
        if (execve(my_strcat(path[i], cmd_name), array, environ)
            != -1)
            return 0;
    if (execve(cmd_name, array, environ) != -1)
        return 0;
    printf("%s: Command not found.\n", array[0]);
    return 1;
}

uchar my_fork(shell_t *shell)
{
    pid_t child = fork();
    int status = 0;

    if (child == -1) {
        perror("fork failed");
        exit(84);
    }
    if (!child)
        return 2;
    else {
        waitpid(child, &status, 0);
        if (WTERMSIG(status))
            printf("Segmentation fault\n");
    }
    return 0;
}

uchar basic_command(shell_t *shell)
{
    char *cmd_name = check_alias(my_str_to_word_array(shell->args->head->line,
        ' ')[0]);

    if (my_fork(shell) == 2)
        my_exec(pop_node(shell->args, shell->args->head));
    return 1;
}