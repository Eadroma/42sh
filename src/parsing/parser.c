/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** read_line
*/

#include "shell.h"


static int fill_array(char **array, vec2i_t *index, char *str, vec2i_t *temp)
{
    array[index->x] = malloc(sizeof(char) * index->y);
    array[index->x++] = clean_str(cut_str(str, temp->x, index->y - 1), ' ');
    array[index->x] = malloc(sizeof(char) * (temp->y + 1));
    array[index->x++] = clean_str(cut_str(str, index->y, index->y + temp->y),
        ' ');
    return index->x;
}

static char **terminate_array(char **array, int index, char *str,
int last_delim)
{
    array[index] = malloc(sizeof(char) * (strlen(str) - (last_delim == 0 ?
        last_delim : last_delim + 1)));
    array[index] = clean_str(cut_str(str, last_delim == 0 ? 0 : last_delim + 2,
        strlen(str)), ' ');
    array[index + 1] = NULL;
    return array;
}


static char **get_args(char *str)
{
    char **args = malloc(sizeof(char *) * (count_delimitors(str) + 2));
    int tmp = 0;
    int idx = 0;
    int last_delim = 0;
    int res = 0;

    for (size_t i = 0; str[i]; i += (tmp == 2 ) ? 2 : 1) {
        if (!str[i + 1] || !(tmp = is_delimitors(str[i], str[i + 1])))
            continue;
        if (!(last_delim = i)) {
            last_delim++;
            args[idx++] = clean_str(cut_str(str, i + (tmp == 2 ? 1 : 0),
                i + tmp), ' ');
            continue;
        }
        idx = fill_array(args, &(vec2i_t){idx, i}, str,
            &(vec2i_t){res, tmp == 2 ? tmp + 1 : tmp});
        res = i + 1;
    }
    return terminate_array(args, idx, str, last_delim);
}

void get_input(shell_t *shell)
{
    list_args_t *list = shell->args;
    char **tokens = NULL;

    if (!shell->command_line || strlen(shell->command_line) < 2)
        return;
    tokens = get_args(shell->command_line);
    for (size_t i = 0; tokens[i]; i++)
        append_node(list, create_node(tokens[i], check_delimitors(tokens[i])));
}