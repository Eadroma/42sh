/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** builtin
*/

#include "struct.h"

#include <unistd.h>

#ifndef BUILTINS_H_
#define BUILTINS_H_

typedef unsigned char uchar;

enum flags_index{
    n_flag,
    e_flag,
    E_flag,
};

typedef struct command_s {
    char *command_name;
    uchar (*handler)(shell_t *shell);
} command_t;

uchar cd_command(shell_t *shell);
uchar env_command(shell_t *shell);
uchar setenv_command(shell_t *shell);
uchar unsetenv_command(shell_t *shell);
uchar echo_command(shell_t *shell);
uchar basic_command(shell_t *shell);
uchar exit_command(shell_t *shell);
uchar alias_command(shell_t *shell);
uchar getenv_command(shell_t *shell);
uchar builtins_loop(shell_t *shell);
uchar display_history(shell_t *shell);

static const command_t COMMANDS[] = {
    {"cd", cd_command},
    {"env", env_command},
    {"setenv", setenv_command},
    {"unsetenv", unsetenv_command},
    {"getenv", getenv_command},
    {"echo", echo_command},
    {"exit", exit_command},
    {"alias", alias_command},
    {"history", display_history}
};


int get_flags_strings_nb(char **array);
bool *get_flags(char **array);


char *search_env(char const *to_find);

static const size_t COMMANDS_COUNT = sizeof(COMMANDS) / sizeof(command_t);


#endif /* !BUILTINS_H_ */