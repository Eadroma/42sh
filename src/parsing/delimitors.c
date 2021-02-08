/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** delimitors
*/

#include "shell.h"

bool check_delimitors(char *to_check)
{
    for (size_t i = 0; delimitors[i]; i++)
        if (my_strincl(to_check, delimitors[i]))
            return true;
    return false;
}

int is_delimitors(char c, char next)
{
    for (size_t i = 0; delimitors[i]; i++)
        if (*delimitors[i] == c)
            return (*delimitors[i] == next) ? 2 : 1;
    return 0;
}

int count_delimitors(char *to_check)
{
    int count = 0;

    for (size_t i = 0; to_check[i]; i++)
        for (size_t j = 0; delimitors[j]; j++) {
            count = (to_check[i] == *delimitors[j]) ? count + 2 : count;
        }
    return count;
}