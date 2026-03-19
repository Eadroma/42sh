/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** delimitors
*/

#include "shell.h"

/**
 * @brief Checks if a given substring contains any active parsing delimiters.
 * 
 * @param to_check The string to evaluate.
 * @return true if a delimiter is found within, false otherwise.
 */
bool check_delimitors(char *to_check)
{
    for (size_t i = 0; delimitors[i]; i++)
        if (my_strincl(to_check, delimitors[i]))
            return true;
    return false;
}

/**
 * @brief Verifies if a character (and potentially its neighbor) forms a known delimiter.
 * 
 * @param c The primary character to check.
 * @param next The subsequent character for double delimiters like `&&` or `||`.
 * @return The sequence length of the matched delimiter (1 or 2), or 0 if ignored.
 */
int is_delimitors(char c, char next)
{
    for (size_t i = 0; delimitors[i]; i++)
        if (*delimitors[i] == c)
            return (*delimitors[i] == next) ? 2 : 1;
    return 0;
}

/**
 * @brief Counts the total character length of all strict delimiters in a command line.
 * 
 * @param to_check The string containing potential delimiters.
 * @return The total aggregate count.
 */
int count_delimitors(char *to_check)
{
    int count = 0;

    for (size_t i = 0; to_check[i]; i++)
        for (size_t j = 0; delimitors[j]; j++) {
            count = (to_check[i] == *delimitors[j]) ? count + 2 : count;
        }
    return count;
}