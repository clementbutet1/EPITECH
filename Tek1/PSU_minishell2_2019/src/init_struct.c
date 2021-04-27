/*
** EPITECH PROJECT, 2019
** init_struct.c
** File description:
** init_struct.c
*/

#include "my.h"
#include"mysh.h"

void init_struct(params_t *params)
{
    params->path_tab = NULL;
    params->cmd = NULL;
    params->path = NULL;
    params->env.envi = NULL;
    params->good_cmd = NULL;
    params->good_path = NULL;
    params->env.old_pwd = 0;
    params->env.pwd = 0;
    params->env.home = 0;
    params->env.str_home = NULL;
    params->env.str_pwd = NULL;
    params->env.str_old_pwd = NULL;
    params->exe = 0;
    params->env.size_envi = 0;
    params->save = NULL;
    params->env.tab_old_pwd = create_tab_old_pwd(params->env.tab_old_pwd);
    params->env.newstr_old_pwd = NULL;
}

int init_struct_pipe(pipe_t *pipe, params_t *params)
{
    pipe->cmd = parse_pipe_cmd(params, pipe);
    int k = 0;
    pipe->fd[2];
    pipe->pid = 0;
    pipe->fdd = 0;
    pipe->path = NULL;
    pipe->len = 0;
    pipe->status = 0;
    pipe->k = 0;
    pipe->redi = 0;
    pipe->tab_redi = NULL;
    pipe->bulletin = 0;

    if (pipe->cmd == NULL) {
        my_putstr("Invalid null command.\n");
        return (84);
    }
    return (0);
}