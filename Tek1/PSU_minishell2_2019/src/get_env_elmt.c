/*
** EPITECH PROJECT, 2019
** get_env_elmt.c
** File description:
** get_env_elmt.c
*/

#include "my.h"
#include"mysh.h"

int check_env_null(params_t *params)
{
    if (params->env.envi == NULL)
        return (11);
    if (check_if_path(params) == 11) {
        params->path = NULL;
        params->path_tab = NULL;
    }
    return (0);
}

void my_getenv_path(params_t *params, char *cmd)
{
    params->path = NULL;

    if (check_env_null(params) == 11)
        return;
    for (int i = 0; params->env.envi[i] != NULL; i++) {
        if (params->env.envi[i][0] == 'P' && params->env.envi[i][1] == 'A'
        && params->env.envi[i][2] == 'T' && params->env.envi[i][3] == 'H') {
            params->path = get_the_path(params->env.envi[i], params);
        }
    }
    if (params->path == NULL)
        return;
    params->path_tab = my_str_tab(params->path, ':');
    return;
}

int get_line_old_pwd(params_t *params)
{
    params->env.old_pwd = 0;

    if (check_env_null(params) == 11)
        return (11);
    for (int i = 0; params->env.envi[i] != NULL; i++) {
        if (params->env.envi[i][0] == 'O' && params->env.envi[i][1] == 'L'
        && params->env.envi[i][2] == 'D' && params->env.envi[i][3] == 'P' &&
        params->env.envi[i][4] == 'W' && params->env.envi[i][5] == 'D') {
            params->env.old_pwd = i;
            params->env.str_old_pwd =
            get_the_path(params->env.envi[i], params);
        }
    }
    return (0);
}

int get_line_pwd(params_t *params)
{
    params->env.pwd = 0;

    for (int i = 0; params->env.envi[i] != NULL; i++) {
        if (params->env.envi[i][0] == 'P' && params->env.envi[i][1] == 'W'
        && params->env.envi[i][2] == 'D') {
            params->env.pwd = i;
            params->env.str_pwd = get_the_path(params->env.envi[i], params);
        }
    }
    return (0);
}

int get_line_home(params_t *params)
{
    params->env.home = 0;
    params->env.str_home = NULL;

    if (check_env_null(params) == 11)
        return (11);
    for (int i = 0; params->env.envi[i] != NULL; i++) {
        if (params->env.envi[i][0] == 'H' && params->env.envi[i][1] == 'O'
        && params->env.envi[i][2] == 'M' && params->env.envi[i][3] == 'E') {
            params->env.home = i;
            params->env.str_home = get_the_path(params->env.envi[i], params);
        }
    }
    return (0);
}