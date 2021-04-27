/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019_orgenise
** File description:
** cd_funct.c
*/

#include "my.h"
#include"mysh.h"

int check_special_cara(params_t *p, char *road_file, char **all_cmd, char *rd)
{
    struct stat sta;

    if (road_file[0] == '~' && road_file[1] == 0) {
        if (chdir(p->env.str_home) == -1) {
            my_putstr(all_cmd[0]);
            my_putstr(": Can't change to home directory.\n");
            return (11);
        } else {
            check_same_env(p, "OLDPWD", rd);
            check_same_old_pwd(p, "OLDPWD", rd);
            return (11);
        }
    }
    if (!((stat(all_cmd[1], &sta) >= 0) && (sta.st_mode > 0) &&
    (S_IEXEC & sta.st_mode))) {
        my_putstr(all_cmd[1]);
        my_putstr(": No such file or directory.\n");
        return (11);
    }
    return (0);
}

int cd_without_env(params_t *params, char *file, char *road, char *s)
{
    if (file[0] == '-' && file[1] == 0)
        if (chdir(params->env.newstr_old_pwd) == -1) {
            my_putstr(file);
            my_putstr(": No such file or directory.\n");
            return (11);
        } else {
            check_same_old_pwd(params, "OLDPWD", road);
            return (11);
        }
    if ((chdir(file)) == -1) {
        my_putstr(file);
        my_putstr(": No such file or directory.\n");
        return (11);
    } else {
        check_same_old_pwd(params, "OLDPWD", road);
        return (11);
    }
    return (0);
}

int check_cd_tiret(char *road_file, params_t *params, char *road, char *cmd)
{
    char s[256];

    if (params->env.envi == NULL) {
        if (cd_without_env(params, road_file, road, s) == 11)
            return (11);
    }
    if (road_file[0] == '-' && road_file[1] == 0) {
        if (chdir(params->env.newstr_old_pwd) == -1) {
            my_putstr(road_file);
            my_putstr(": No such file or directory.\n");
            return (11);
        } else {
            check_same_env(params, "OLDPWD", road);
            check_same_old_pwd(params, "OLDPWD", road);
            return (11);
        }
    }
    return (1);
}

int check_arg_cd(params_t *params, char *road_file, char **cmd, char *road)
{
    struct stat sta;

    if (cmd[2] != NULL) {
        my_putstr(cmd[0]);
        my_putstr(": Too many arguments.\n");
        return (11);
    }
    if (cmd[0] != NULL && cmd[1] == NULL) {
        if (chdir(params->env.str_home) == -1) {
            my_putstr(cmd[0]);
            my_putstr(": Can't change to home directory.\n");
            return (11);
        } else {
            check_same_env(params, "OLDPWD", road);
            check_same_old_pwd(params, "OLDPWD", road);
            return (11);
        }
    }
    return (0);
}

void check_cd(params_t *params, char *file, char *cmd, char **all_cmd)
{
    char s[256];
    char *road = getcwd(s, 256);
    char *road_file = all_cmd[1];
    get_line_old_pwd_special_tab(params);

    if (check_arg_cd(params, file, all_cmd, road) == 11)
        return;
    if (check_cd_tiret(road_file, params, road, cmd) == 11)
        return;
    if (check_special_cara(params, file, all_cmd, road) == 11)
        return;
    if (chdir(road_file) == -1) {
        my_putstr(road_file);
        my_putstr(": Not a directory.\n");
    }
    check_same_env(params, "OLDPWD", road);
    check_same_old_pwd(params, "OLDPWD", road);
    return;
}