/*
** EPITECH PROJECT, 2020
** PSU_my_exec_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdbool.h>

char *my_strchr(char *str, char const delim);
bool my_strcmp(char const *a, char const *b);
char **my_str_to_word_array(char *str, char c);
int my_array_len(char **array);
int my_strlen(char const *str);
char *my_strcat(char const *s1, char const *s2);
char **my_realloc_array(char **array, int size);
bool my_strincl(char const *str, char const *part);
void remove_line_array(char **array, int i);
char  **clean_array(char **array, char *str);
char *clean_str(char *str, char c);
char *remove_char(char *str, int i);
char *cut_str(char *str, int start, int end);
char *remove_first_word(char *str, char delim);
int my_array_len(char **array);
char *end_str(char *str, char delim);

#endif /* !MY_H_ */
