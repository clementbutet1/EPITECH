/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** check_unsetenv.c
*/

#include "mysh.h"

int does_env_exist(char **exe, sh_t *sh)
{
    char *name = exe[1];
    int d = 0;
    int a = 0;
    int i = 0;
    int g = my_strlen(exe[1]);

    for (; sh->path.env[d] != NULL; d++) {
        for (i = 0, a = 0; i < g && sh->path.env[d][i] != '\0'; i++) {
            if (sh->path.env[d][i] == name[i])
                a++;
        }
        if (a == g) {
            g = -1;
            break;
        }
    }
    if (g == -1)
        return (d);
    return (-1);
}

void rm_env(sh_t *sh, int d)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (sh->taille_env));

    for (int a = 0; sh->path.env[a] != NULL; i++, a++) {
        if (a != d)
            new_env[i] = sh->path.env[a];
        else
            i--;
    }
    new_env[i] = NULL;
    free(sh->path.env);
    sh->path.env = new_env;
    sh->taille_env -= 1;
}

void modif_env2_rm(char **exe, sh_t *sh)
{
    int i = 1;
    int d = 0;

    while (exe[i] != NULL) {
        d = does_env_exist(exe, sh);
        if (d != -1)
            rm_env(sh, d);
        i++;
    }
}

void modif_env_rm(char **exe, sh_t *sh)
{
    int i = 0;

    while (exe[i] != NULL)
        i++;
    if (i < 2) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("unsetenv: Too few arguments.\n");
    }
    if (sh->parenth == 1)
        return;
    else {
        i = 1;
        while (exe[i] != NULL) {
            add_equal(exe, my_strlen(exe[i]));
            i++;
        }
        modif_env2_rm(exe, sh);
    }
}

int check_unsetenv(char **exe, sh_t *sh)
{
    char *unsetenv = "unsetenv";
    int a = 0;
    int i = 0;

    if (my_strcmp(unsetenv, exe[0]) != 0)
        return (0);
    for (; i < 8 && exe[0][i] != '\0'; i++) {
        if (exe[0][i] == unsetenv[i])
            a++;
        else
            return (0);
    }
    if (exe[0][i] != ' ' && exe[0][i] != '\0')
        return (0);
    if (a == 8)
        modif_env_rm(exe, sh);
    return (1);
}