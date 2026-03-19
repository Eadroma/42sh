/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** read_line
*/

#include "shell.h"


/**
 * @brief Extracts and stores a token argument block into the master parsing array.
 * 
 * @param array The destination token string array.
 * @param index Pointer carrying the current array and index tracking states.
 * @param str The source string to cut the element from.
 * @param temp Struct holding sub-index tracking parameters.
 * @return The updated position pointer within the destination array.
 */
static int fill_array(char **array, vec2i_t *index, char *str, vec2i_t *temp)
{
    array[index->x] = malloc(sizeof(char) * (index->y - temp->x + 1));
    array[index->x++] = clean_str(cut_str(str, temp->x, index->y), ' ');
    array[index->x] = malloc(sizeof(char) * (temp->y + 1));
    array[index->x++] = clean_str(cut_str(str, index->y, index->y + temp->y),
        ' ');
    return index->x;
}

/**
 * @brief Validates the parsed token array constraints and applies a NULL sentinel block.
 * 
 * @param array The fully formulated token array.
 * @param index The active limit index pointing to the array ceiling.
 * @param str The baseline processing string.
 * @param res String index pointing to the start of the final trailing block.
 * @return The fully realized parsing array matrix.
 */
static char **terminate_array(char **array, int index, char *str,
int res)
{
    array[index] = malloc(sizeof(char) * (strlen(str) - res + 1));
    array[index] = clean_str(cut_str(str, res, strlen(str)), ' ');
    array[index + 1] = NULL;
    return array;
}

/**
 * @brief Core lexer matching tokens against logical/pipe delimiters.
 * 
 * Splits the raw command line into functional argument blocks separated
 * naturally by operators like &&, ||, ;, and |.
 * 
 * @param str The completely raw input command buffer.
 * @return Pointer containing structured token chunks isolated individually.
 */
static char **get_args(char *str)
{
    char **args = malloc(sizeof(char *) * (count_delimitors(str) + 2));
    int tmp = 0;
    int idx = 0;
    int res = 0;

    for (size_t i = 0; str[i]; i += (tmp == 2) ? 2 : 1) {
        if (!str[i + 1] || !(tmp = is_delimitors(str[i], str[i + 1])))
            continue;
        if (res == (int)i) {
            args[idx++] = clean_str(cut_str(str, i, i + tmp), ' ');
            res = i + tmp;
            continue;
        }
        idx = fill_array(args, &(vec2i_t){idx, i}, str,
            &(vec2i_t){res, tmp});
        res = i + tmp;
    }
    return terminate_array(args, idx, str, res);
}

/**
 * @brief Main terminal capture orchestrator directing input toward lexers and evaluators.
 * 
 * Reads raw lines, requests tokens mapping from `get_args`, and packages them into
 * the global argument linked lists for eventual command dispatching.
 * 
 * @param shell Main context reference tracking arguments sequence.
 */
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