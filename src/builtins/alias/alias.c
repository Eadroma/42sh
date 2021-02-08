/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** alias
*/

#include "shell.h"

int display_alias(void)
{
    char **alias = read_alias_file(fopen(".alias", "r"));

    if (!alias)
        return 1;
    for (size_t i = 0; alias[i]; i++)
        printf("%s\n", alias[i]);
    return 0;
}

int find_alias(char *to_find)
{
    char **alias = read_alias_file(fopen(".alias", "r"));

    if (!alias)
        return 1;
    for (size_t i = 0; alias[i]; i++)
        if (my_strincl(*my_str_to_word_array(alias[i], ' '), to_find)) {
            printf("%s\n", clean_str(my_str_to_word_array(alias[i], ' ')[1], ' '
                ));
            return 0;
        }
    return 1;
}

uchar alias_command(shell_t *shell)
{
    char **args = my_str_to_word_array(shell->args->head->line, ' ');
    int len = my_array_len(args);

    if (len < 3)
        return (len == 1) ? display_alias() : find_alias(args[1]);
    return write_alias(shell);
}