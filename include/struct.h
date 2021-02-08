/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** struct
*/

#include <stddef.h>
#include <stdio.h>
#ifndef STRUCT_H_
#define STRUCT_H_

typedef unsigned char uchar;

enum separators_index
{
    and_sep,
    pipes,
    or_sep,
    simple_standard_input,
    double_standard_input,
    simple_standard_output,
    double_standard_output,
    semicolon
};

typedef struct vec2i_s
{
    int x;
    int y;
} vec2i_t;

typedef struct bool2_s
{
    bool is_first;
    bool is_last;
} bool2_t;

static const char *delimitors[] = {"&&", "|","<", ">", ";"};
static const int max_delimitors = sizeof(delimitors) / sizeof(*delimitors);

typedef struct args_s {
    char *line;
    bool is_delim;
    struct args_s *next;
    struct args_s *prev;
} args_t;

typedef struct list_args_s {
    size_t index;
    args_t *head;
} list_args_t;

typedef struct alias_s {
    char **alias;
    struct alias_s *next;
    struct alias_s *prev;
} alias_t;

typedef struct list_alias_s {
    alias_t *head;
    size_t size;
} list_alias_t;

typedef struct shell_s
{
    int fd;
    char *command_line;
    list_args_t *args;
    list_alias_t *list_alias;
} shell_t;


shell_t *init_shell(void);

bool check_delimitors(char *to_check);
int is_delimitors(char c, char next);
int count_delimitors(char *to_check);

alias_t *create_alias(char **array);
list_alias_t *init_alias_list(void);

args_t *create_node(char *array, bool is_delim);
void insert_node(args_t *head, args_t *node);
bool append_node(list_args_t *list, args_t *node);
args_t *pop_index_node(list_args_t *list, int index);
args_t *pop_node(list_args_t *list, args_t *node);
list_args_t *reset_list(list_args_t *list);
void display_list(list_args_t *list);

char *clean_cmd_line(char *line);

void insert_alias(alias_t *head, alias_t *node);
bool append_alias(list_alias_t *list, alias_t *node);
void modify_alias(alias_t *node, char **array);
int display_alias(void);
int find_alias(char *to_find);
char **read_alias_file(FILE *stream);
int write_alias(shell_t *shell);
void fill_alias(shell_t *shell);
char *check_alias(char *cmd_name);

#endif /* !STRUCT_H_ */
