/*
** EPITECH PROJECT, 2020
** get next line
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Strips leading separation characters and inline newlines.
 * 
 * @param str The input string to sanitize.
 * @param c The repeated separator character to ignore.
 * @return Safely terminated and shifted string sequence pointer.
 */
char *clean_str(char *str, char c)
{
    for (; str[0] && (str[0] == c || str[0] == '\n'); str++);
    for (size_t i = 0; str[i]; i++)
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    return str;
}

/**
 * @brief Calculates length of a specific word bounded by delimiter or newline.
 * 
 * @param str The substring beginning with a word.
 * @param c The separator boundary character.
 * @return Character length of the word segment.
 */
static int my_word_len(char const *str, char c)
{
    size_t i = 0;

    for (; str[i] && str[i] != c && str[i] != '\n'; i++);
    return i;
}

/**
 * @brief Counts the total possible number of extracted split elements.
 * 
 * @param str Formatted input string sequence.
 * @param c Separator boundary char.
 * @return Total discrete word count + 1.
 */
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

/**
 * @brief Copies an exact length sequence off a string into an independent buffer.
 * 
 * @param str Reading source string.
 * @param len Byte capacity count to slice.
 * @return Distinct NULL-capped extraction string.
 */
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

/**
 * @brief Splits a string over a delimiter character mapping segments into array blocks.
 * 
 * Standard libmy implementation similar to string.split.
 * 
 * @param str Source string input buffer.
 * @param c Segmentation delimeter token char.
 * @return Array matrix of split tokens. Exits to 84 natively on memory failures.
 */
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