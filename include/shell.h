/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** shell
*/


#include "my.h"
#include "builtin.h"

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#ifndef SHELL_H_
#define SHELL_H_


int shell_loop(void);
void display_prompt(void);

bool check_delimitors(char *to_check);
void get_input(shell_t *shell);
char **get_path_array(void);
int exec_loop(shell_t *shell);


uchar and_delimitor(shell_t *shell, bool2_t pos);
uchar or_delimitor(shell_t *shell, bool2_t pos);
uchar my_pipe(shell_t *shell, bool2_t pos);
uchar simple_standard_input_redirection(shell_t *shell, bool2_t pos);
uchar double_standard_input_redirection(shell_t *shell, bool2_t pos);
uchar standard_output_redirection(shell_t *shell, bool2_t pos);
uchar semicolon_delimitor(shell_t *shell, bool2_t pos);

typedef struct delimitor_s {
    char *delimitor;
    uchar (*handler)(shell_t *shell, bool2_t pos);
} delimitor_t;

static const delimitor_t DELIMITORS[] = {
    {"&&", and_delimitor},
    {"||", or_delimitor},
    {"|", my_pipe},
    {"<", simple_standard_input_redirection},
    {"<<", double_standard_input_redirection},
    {">", standard_output_redirection},
    {">>", standard_output_redirection},
    {";", semicolon_delimitor}
};


uchar get_delim(shell_t *shell);

char *search_in_env(char const *to_find);

uchar my_exec(args_t *args);
uchar my_fork(shell_t *shell);
uchar my_dup(shell_t *shell, int fd);


uchar redirections_error_management(shell_t *shell, bool2_t pos);
char *get_filename(shell_t *shell);


void add_to_history(shell_t *shell);
void read_from_history(int op);


uchar reset_fd(shell_t *shell, int save, int fd);

void free_array(char **array);
char **read_file(FILE *stream);


static const size_t DELIMITORS_COUNT = sizeof(DELIMITORS) / sizeof(delimitor_t);

#endif /* !SHELL_H_ */
