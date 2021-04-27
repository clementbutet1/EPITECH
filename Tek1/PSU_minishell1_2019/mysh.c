/*
** EPITECH PROJECT, 2019
** mysh.c
** File description:
** mysh.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include"include/mysh.h"

void init_struct(params_t *params)
{
    params->path_tab = NULL;
    params->cmd = NULL;
    params->path = NULL;
    params->envi = NULL;
    params->good_cmd = NULL;
    params->good_path = NULL;
    params->old_pwd = 0;
    params->pwd = 0;
    params->home = 0;
    params->str_home = NULL;
    params->str_pwd = NULL;
    params->str_old_pwd = NULL;
    params->exe = 0;
    params->save_str_old_pwd = NULL;
    params->size_envi = 0;
    params->save = NULL;
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
    params->size_envi = 0;

    if (check_envi(env) == 11) {
        params->envi = NULL;
        return;
    }
    for (; env[params->size_envi] != NULL; params->size_envi++);
    params->envi = malloc(sizeof(char *) * params->size_envi + 1);
    for (int i = 0; env[i] != NULL; i++) {
        params->envi[i] = my_strdup(env[i]);
    }
}

void boucl_inf(char **env, params_t *params)
{
    char *cmd = NULL;

    funct_get_line(cmd, params);
    while (11) {
        cmd = NULL;
        my_putstr("$> ");
        funct_get_line(cmd, params);
    }
}

int main(int ac, char **av, char **env)
{
    params_t params;

    if (ac != 1)
        exit (84);
    init_struct(&params);
    create_envi(env, &params);
    my_putstr("$> ");
    boucl_inf(env, &params);
    return (0);
}