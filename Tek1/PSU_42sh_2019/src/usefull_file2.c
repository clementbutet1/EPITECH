/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** usefull_file2.c
*/

#include "mysh.h"

int free_all(char **exe)
{
    for (int i = 0; exe[i] != NULL; i++)
        free(exe[i]);
    free(exe);
    return (0);
}

int free_end(sh_t *sh)
{
    for (int i = 0; sh->path.env[i] != NULL; i++)
        free(sh->path.env[i]);
    free(sh->path.env);
    if (sh->path.pwd != NULL)
        free(sh->path.pwd);
    if (sh->path.oldpwd != NULL)
        free(sh->path.oldpwd);
    free_alias_tab(sh);
    return (0);
}

void add_equal(char **exe, int len)
{
    char *str = malloc(sizeof(char) * len + 2);
    int a = 0;

    for (; a < len; a++)
        str[a] = exe[1][a];
    str[a++] = '=';
    str[a] = '\0';
    free(exe[1]);
    exe[1] = str;
}