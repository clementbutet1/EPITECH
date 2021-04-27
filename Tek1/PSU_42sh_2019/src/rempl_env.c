/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** rempl_env.c
*/

#include "mysh.h"

void replace_env2(sh_t *sh, char *str, char *name)
{
    char **env = malloc(sizeof(char *) * (sh->taille_env + 1));
    int i = 0;
    char *pwd = my_strcat(name, str);

    for (int i = 0; sh->path.env[i] != NULL; i++)
        env[i] = sh->path.env[i];
    env[i++] = pwd;
    env[i] = NULL;
    free(sh->path.env);
    sh->taille_env += 1;
    sh->path.env = env;
}

void replace_env(sh_t *sh, char *str, char *name)
{
    int g = my_strlen(name);
    int d = 0;
    int a = 0;
    int i = 0;

    for (; sh->path.env[d] != NULL; d++) {
        for (i = 0, a = 0; i < g && sh->path.env[d][i] != '\0'; i++) {
            if (sh->path.env[d][i] == name[i])
                a++;
        }
        if (a == g)
            break;
    }
    if (sh->path.env[d] == NULL)
        replace_env2(sh, str, name);
    else {
        free(sh->path.env[d]);
        sh->path.env[d] = my_strcat(name, str);
    }
}