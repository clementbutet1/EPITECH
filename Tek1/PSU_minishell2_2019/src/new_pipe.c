/*
** EPITECH PROJECT, 2019
** new_pipe.c
** File description:
** new_pipe.c
*/

#include "my.h"
#include "mysh.h"

int prepare_pipe(params_t *params, int i)
{
    pipe_t pipe;

    if (init_struct_pipe(&pipe, params) == 84)
        return (11);
    execute_pipe(params, &pipe);
    return (11);
}

int check_bulletin(params_t *pa, pipe_t *p, int k)
{
    char *built_in[6] = {"setenv", "unsetenv", "env", "cd", "exit", NULL};

    for (int i = 0; built_in[i]; i++)
        if (check_same_word(p->cmd[k][0], built_in[i]) == 11)
            return (1);
    return (0);
}

void execute_cmd_pipe(params_t *params, pipe_t *p, char **cmd_tab, char *cmd)
{
    int error = 0;
    int status;
    prepare_check_access(params, p, p->k);

    if (find_bulltin(params, cmd, cmd_tab) != 0)
        return;
    if (params->cmd[0][0] == '/') {
        error = execve(p->path, p->cmd[p->k], params->env.envi);
        check_error_excve(put_tab_buffer(p->cmd[p->k]), params, error);
        exit(0);
    }
    error = execve(p->path, p->cmd[p->k], params->env.envi);
    check_error_excve_pipe(put_tab_buffer(p->cmd[p->k]), params, error);
    exit(0);
    return;
}