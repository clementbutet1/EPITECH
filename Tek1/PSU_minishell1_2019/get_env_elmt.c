/*
** EPITECH PROJECT, 2019
** get_env_elmt.c
** File description:
** get_env_elmt.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include"include/mysh.h"

int check_env_null(params_t *params)
{
    if (params->envi == NULL)
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
    for (int i = 0; params->envi[i] != NULL; i++) {
        if (params->envi[i][0] == 'P' && params->envi[i][1] == 'A'
        && params->envi[i][2] == 'T' && params->envi[i][3] == 'H') {
            params->path = get_the_path(params->envi[i], params);
        }
    }
    if (params->path == NULL)
        return;
    params->path_tab = my_str_tab(params->path, ':');
    return;
}

int get_line_old_pwd(params_t *params)
{
    params->old_pwd = 0;

    if (check_env_null(params) == 11)
        return (11);
    for (int i = 0; params->envi[i] != NULL; i++) {
        if (params->envi[i][0] == 'O' && params->envi[i][1] == 'L'
        && params->envi[i][2] == 'D' && params->envi[i][3] == 'P' &&
        params->envi[i][4] == 'W' && params->envi[i][5] == 'D') {
            params->old_pwd = i;
            params->str_old_pwd = get_the_path(params->envi[i], params);
        }
    }
    return (0);
}

int get_line_pwd(params_t *params)
{
    params->pwd = 0;

    for (int i = 0; params->envi[i] != NULL; i++) {
        if (params->envi[i][0] == 'P' && params->envi[i][1] == 'W'
        && params->envi[i][2] == 'D') {
            params->pwd = i;
            params->str_pwd = get_the_path(params->envi[i], params);
        }
    }
    return (0);
}

int get_line_home(params_t *params)
{
    params->home = 0;
    params->str_home = NULL;

    if (check_env_null(params) == 11)
        return (11);
    for (int i = 0; params->envi[i] != NULL; i++) {
        if (params->envi[i][0] == 'H' && params->envi[i][1] == 'O'
        && params->envi[i][2] == 'M' && params->envi[i][3] == 'E') {
            params->home = i;
            params->str_home = get_the_path(params->envi[i], params);
        }
    }
    return (0);
}

