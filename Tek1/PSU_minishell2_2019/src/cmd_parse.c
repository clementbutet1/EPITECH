/*
** EPITECH PROJECT, 2019
** cmd_parse.c
** File description:
** cmd_parse.c
*/

#include "my.h"
#include"mysh.h"

int check_if_pipe(params_t *params, char *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i++)
        if (cmd[i] == '|')
            return (11);
    return (0);
}

void exe_cmd(params_t *params, char **cmd)
{
    if (find_bulltin(params, cmd[0], cmd) == 0) {
        params->good_path = check_good_cmd(cmd[0], params);
        if (check_execute_cmd(cmd[0], params, cmd) == 1);
    }
}

void launch_cmd(params_t *params, char *cmd)
{
    for (int i = 0; params->cmd_parse[i] != NULL; i++) {
        params->cmd = copy_tab(params->cmd_parse[i]);
        if (check_if_pipe(params, put_tab_buffer(params->cmd)) == 11) {
            check_pipe(params, cmd);
            continue;
        }
        if (find_bulltin(params, cmd, params->cmd) == 0) {
            params->good_path = check_good_cmd(cmd, params);
            if (check_execute_cmd(cmd, params, params->cmd) == 1);
        }
    }
    return;
}

void create_cmd_tab(params_t *params, char *cmd)
{
    int size = 0;
    int i = 0;
    int j = 0;
    params->all_cmd = my_str_tab(cmd, ';');

    for (; params->all_cmd[size] != NULL; size++);
    params->cmd_parse = malloc(sizeof(char **) * (size + 2));
    for (; params->all_cmd[j] != NULL; j++) {
        params->all_cmd[j] = clean_str(params->all_cmd[j], params);
        params->cmd_parse[i] = my_str_tab(params->all_cmd[j], ' ');
        i++;
    }
    params->cmd_parse[i] = NULL;
    return;
}