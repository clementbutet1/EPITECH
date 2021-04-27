/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** env.c
*/

#include "my.h"
#include"mysh.h"

void print_env(params_t *params, char **all_cmd)
{
    if (params->env.envi == NULL)
        return;
    if (all_cmd[1] != NULL) {
        my_putstr(all_cmd[0]);
        my_putstr(": ");
        my_putstr(all_cmd[1]);
        my_putstr(": No such file or directory\n");
        return;
    }
    for (int i = 0; params->env.envi[i] != NULL; i++) {
        my_putstr(params->env.envi[i]);
        my_putchar('\n');
    }
}

int check_envi(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'W'
            && env[i][2] == 'D')
            return (0);
    }
    return (11);
}

void create_envi(char **env, params_t *params)
{
    params->env.size_envi = 0;
    int i = 0;

    if (check_envi(env) == 11) {
        params->env.envi = NULL;
        return;
    }
    for (; env[params->env.size_envi] != NULL; params->env.size_envi++);
    params->env.envi = malloc(sizeof(char *) * (params->env.size_envi + 1));
    for (; env[i] != NULL; i++) {
        params->env.envi[i] = my_strdup(env[i]);
    }
    params->env.envi[i] = NULL;
}