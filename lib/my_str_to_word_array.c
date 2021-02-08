/*
** EPITECH PROJECT, 2020
** get next line
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>

char *clean_str(char *str, char c)
{
    for (; str[0] && (str[0] == c || str[0] == '\n'); str++);
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    return str;
}

static int my_word_len(char const *str, char c)
{
    size_t i = 0;

    for (; str[i] && str[i] != c && str[i] != '\n'; i++);
    return i;
}

static int count_words(char *str, char c)
{
    int nb = 0;

    str = clean_str(str, c);
    for (int i = 0; str[i] && str[i + 1]; i++)
        if ((str[i] == c || str[i] == '\n')
            && (str[i + 1] != c || str[i + 1] != '\n'))
            nb++;
    return nb + 1;
}

static char *fill_str(char const *str, int len)
{
    char *dest = malloc(sizeof(char) * len + 1);

    if (!dest)
        return NULL;
    for (int i = 0; i < len ; i++)
        dest[i] = str[i];
    dest[len] = '\0';
    return dest;
}

char **my_str_to_word_array(char *str, char c)
{
    int len = 0;
    int nb_words = 0;
    char **array =  NULL;


    if (!str)
        return NULL;
    nb_words = count_words(str, c);
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (!array)
        exit(84);
    for (int i = 0; i < nb_words; i++) {
        str = clean_str(str, c);
        len = my_word_len(str, c);
        array[i] = fill_str(str, len);
        str += len;
    }
    array[nb_words] = NULL;
    return array;
}