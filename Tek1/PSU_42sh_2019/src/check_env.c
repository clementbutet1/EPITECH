/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** check_env.c
*/

#include "mysh.h"

void print_env(sh_t *sh)
{
    for (int i = 0; sh->path.env[i] != NULL; i++) {
        my_putstr(sh->path.env[i]);
        my_putchar('\n');
    }
}

int check_env(char **exe, sh_t *sh)
{
    char *env = "env";
    int a = 0;
    int i = 0;

    for (; i < 3 && exe[0][i] != '\0'; i++) {
        if (exe[0][i] == env[i])
            a++;
        else
            return (0);
    }
    for (; exe[0][i] != '\0' && exe[0][i] != '\n'; i++) {
        if (exe[0][i] != ' ')
            return (0);
    }
    if (a == 3)
        print_env(sh);
    return (1);
}