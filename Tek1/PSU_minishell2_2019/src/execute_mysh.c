/*
** EPITECH PROJECT, 2019
** execute_mysh.c
** File description:
** execute_mysh.c
*/

#include "my.h"
#include"mysh.h"

char *check_good_cmd(char *cmd, params_t *params)
{
    char *rslt = NULL;
    int len = my_strlen(params->cmd[0]);

    if (params->env.envi == NULL || params->path_tab == NULL)
        return (rslt);
    rslt = check_executable(cmd, params);
    if (rslt == NULL) {
        rslt = check_access(len, rslt, params);
    } else {
        return (rslt);
    }
}

int check_execute_cmd(char *cmd, params_t *params, char **all_cmd)
{
    if (params->env.envi == NULL) {
        (check_in_the_file(cmd, params, all_cmd) == 11);
        return (11);
        if (check_same_word(params->cmd[0], "cd") != 11) {
            my_putstr(cmd);
            my_putstr(": Command not found.\n");
        }
    } else {
        execute_cmd(cmd, params, all_cmd);
    }
}

void check_cmd(char *cmd, params_t *params)
{
    char s[256];
    char *road;
    road = getcwd(s, 256);
    params->exe = 0;

    get_line_old_pwd(params);
    check_same_env(params, "PWD", road);
    my_getenv_path(params, cmd);
    if ((check_entry(cmd) == 1))
        return;
    cmd = clean_str(cmd, params);
    create_cmd_tab(params, cmd);
    launch_cmd(params, cmd);
    return;
}