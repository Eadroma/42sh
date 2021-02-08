/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** remove_char
*/

char *remove_char(char *str, int i)
{
    for (; str[i + 1]; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    return str;
}