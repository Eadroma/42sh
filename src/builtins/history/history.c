/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** history
*/

#include "shell.h"

/**
 * @brief Reads lines from a file stream entirely into a dynamic string array.
 * 
 * @param stream The open file stream to read from.
 * @return NULL-terminated array of strings.
 */
char **read_file(FILE *stream)
{
    int i = 0;
    char **file = malloc(sizeof(char *) * 2);
    size_t len = 0;

    if (!file || !stream)
        return NULL;
    for (int i = 0; i < 2; i++)
        file[i] = NULL;
    for (; getline(&file[i], &len, stream) != -1; i++) {
        file[i] = clean_str(file[i], '\n');
        file = my_realloc_array(file, i + 2);
    }
    file[i] = NULL;
    return file;
}

/**
 * @brief Appends the current shell command line to the `.history` file.
 * 
 * @param shell The main shell state.
 */
void add_to_history(shell_t *shell)
{
    int fd = open(".history", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == 1) {
        perror("open");
        return;
    }
    write(fd, shell->command_line, strlen(shell->command_line));
    write(fd, "\n", 1);
    close(fd);
}

/**
 * @brief Retrieves and prints a specific line relative to history file navigation.
 * 
 * @param opt Direction offset (-1 for prev, 1 for next).
 */
void read_from_history(int opt) // opt = -1 || opt = 1 (prev or next)
{
    char **history = read_file(fopen(".history", "r"));
    int line_max = my_array_len(history);
    int line = 0;
    static int i = 0;

    if (!history)
        return;
    i += opt;
    if ((line = line_max + i) > line_max || line < 0)
        return;
    printf("%s\n", history[line]);
    free_array(history);
}

/**
 * @brief Executes the built-in 'history' command, displaying all previous commands.
 * 
 * @param shell The main shell state.
 * @return 0 on success, or 84 if history reading fails.
 */
uchar display_history(shell_t *shell)
{
    (void)shell;
    char **history = read_file(fopen(".history", "r"));

    if (!history)
        return 84;
    for (size_t i = 0; history[i]; i++)
        printf("\t%ld\t%s\n", i, history[i]);
    free_array(history);
    return 0;
}