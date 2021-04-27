/*
** EPITECH PROJECT, 2019
** funct_cd.c
** File description:
** funct_cd.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "include/mysh.h"

int check_special_cara(params_t *params, char *road_file, char *cmd, char *rd)
{
    struct stat sta;

    if (road_file[0] == '~' && road_file[1] == 0) {
        if (chdir(params->str_home) == -1) {
            my_putstr(params->cmd[0]);
            my_putstr(": Can't change to home directory.\n");
            return (11);
        } else {
            check_same_env(params, "OLDPWD", rd);
            return (11);
        }
    }
    if (!((stat(params->cmd[1], &sta) >= 0) && (sta.st_mode > 0) &&
    (S_IEXEC & sta.st_mode))) {
        my_putstr(params->cmd[1]);
        my_putstr(": Not a directory.\n");
        return (11);
    }
    return (0);
}

int cd_without_env(params_t *params, char *file, char *cmd)
{
    char s[256];
    char *road = getcwd(s, 256);
    char *road_file = params->cmd[1];

    if ((chdir(road_file)) == -1) {
        my_putstr(road_file);
        my_putstr(": No such file or directory.\n");
        return (11);
    } else
        return (11);
    return (0);
}

int check_cd_tiret(char *road_file, params_t *params, char *road, char *cmd)
{
    if (params->envi == NULL) {
        if (cd_without_env(params, road_file, cmd) == 0)
            return (11);
    }
    if (road_file[0] == '-' && road_file[1] == 0) {
        if (chdir(params->str_old_pwd) == -1) {
            my_putstr(": No such file or directory.\n");
            return (11);
        } else {
            check_same_env(params, "OLDPWD", road);
            return (11);
        }
    }
    return (1);
}

int check_arg_cd(params_t *params, char *road_file, char *cmd, char *road)
{
    struct stat sta;

    if (params->cmd[2] != NULL) {
        my_putstr(params->cmd[0]);
        my_putstr(": Too many arguments.\n");
        return (11);
    }
    if (params->cmd[0] != NULL && params->cmd[1] == NULL) {
        if (chdir(params->str_home) == -1) {
            my_putstr(params->cmd[0]);
            my_putstr(": Can't change to home directory.\n");
            return (11);
        } else {
            check_same_env(params, "OLDPWD", road);
            return (11);
        }
    }
    return (0);
}

void check_cd(params_t *params, char *file, char *cmd)
{
    char s[256];
    char *road = getcwd(s, 256);
    char *road_file = params->cmd[1];

    if (check_arg_cd(params, file, cmd, road) == 11)
        return;
    if (check_cd_tiret(road_file, params, road, cmd) == 11)
        return;
    if (check_special_cara(params, file, cmd, road) == 11)
        return;
    if (chdir(road_file) == -1) {
        my_putstr(road_file);
        my_putstr(": No such file or directory.\n");
    }
    check_same_env(params, "OLDPWD", road);
    return;
}