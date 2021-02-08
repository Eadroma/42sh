/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** save_alias
*/

#include "shell.h"

char **read_alias_file(FILE *stream)
{
    size_t i = 0;
    char **file = malloc(sizeof(char *) * 2);
    size_t len = 0;

    if (!file || !stream)
        return NULL;
    for (size_t j = 0; j < 2; j++)
        file[j] = NULL;
    for (; getline(&file[i], &len, stream) != -1; i++) {
        file[i] = clean_str(file[i], '\n');
        file[i] = clean_str(file[i], ' ');
        file = my_realloc_array(file, i + 2);
    }
    file[i] = NULL;
    return file;
}

int write_alias(shell_t *shell)
{
    int fd = open(".alias", O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR |
        S_IRGRP | S_IROTH);
    char *to_add = cut_str(shell->command_line, 5, strlen(shell->command_line));

    if (fd == 1) {
        perror("open");
        return 84;
    }
    write(fd, my_strcat(to_add, "\n"), strlen(to_add) + 1);
    append_alias(shell->list_alias, create_alias(my_str_to_word_array(to_add,
        ' ')));
    close(fd);
    return 0;
}

void fill_alias(shell_t *shell)
{
    list_alias_t *list = shell->list_alias;
    char **alias_saved = read_alias_file(fopen(".alias", "r"));

    if (!alias_saved)
        return;
    for (size_t i = 0; alias_saved[i]; i++) {
        append_alias(list, create_alias(my_str_to_word_array(clean_str(
            alias_saved[i], '\n'), ' ')));
    }
}