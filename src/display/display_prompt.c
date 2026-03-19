/*
** EPITECH PROJECT, 2020
** B-PSU-210-PAR-2-2-42sh-victoire.rabeau
** File description:
** display_prompt
*/

#include "shell.h"

/**
 * @brief Extracts the last few directories of the current working directory.
 * 
 * Truncates the absolute path to keep the prompt compact.
 * 
 * @return Pointer within the allocated CWD string representing the local path.
 */
static char *get_current_dir(void)
{
    char *dir = getcwd(NULL, 0);
    int res = 0;

    for (int i = 0; dir[i]; i++) {
        if (dir[i] == '/' && res < 3) {
            res++;
            dir = dir + i + 1;
            i = 0;
        }
    }
    return dir;
}

/**
 * @brief Prints the interactive shell prompt with the current directory.
 */
void display_prompt(void)
{
    printf("[%s]$ ", get_current_dir());
}

/**
 * @brief Iterates over the global environ array and prints each key-value pair.
 */
void display_env(void)
{
    extern char **environ;

    for (int i = 0; environ[i]; i++)
        printf("%s\n", environ[i]);
}