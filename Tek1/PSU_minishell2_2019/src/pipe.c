/*
** EPITECH PROJECT, 2019
** pipe.c
** File description:
** pipe.c
*/

#include "my.h"
#include "mysh.h"

void pid_diff(params_t *pa, int in, int pid, pipe_t *p)
{
    int status;

    if (p->bulletin == 1) {
        wait(NULL);
        waitpid(pid, &status, 0);
        check_error_segfault(status);
    }
    if (p->bulletin == 1)
        find_bulltin(pa, put_tab_buffer(p->cmd[p->k]), p->cmd[p->k]);
    return;
}

int add_child_process(params_t *pa, int in, int out, pipe_t *p)
{
    int pid = fork();

    if (pid == 0) {
        if (in != 0)
            dup2(in, 0);
        if (out != 1)
            dup2(out, 1);
        if (check_bulletin(pa, p, p->k) == 1) {
            find_bulltin(pa, put_tab_buffer(p->cmd[p->k]), p->cmd[p->k]);
            exit (0);
        }
        dup2(out, 1);
        execute_cmd_pipe(pa, p, p->cmd[p->k], p->cmd[p->k][0]);
    } else {
        pid_diff(pa, in, pid, p);
    }
}

void condi_redi_pipe(params_t *pa, pipe_t *p, int *pipes, int in)
{
    int op = 0;

    if (check_redirection_pipe(pa, p, p->k) == 11) {
        prepare_check_access(pa, p, p->k);
        add_child_process(pa, in, op, p);
    } else {
        prepare_check_access(pa, p, p->k);
        add_child_process(pa, in, pipes[1], p);
    }
}

int execute_pipe(params_t *params, pipe_t *p)
{
    int in = 0;
    int pipes[2] = {-1, -1};
    int size = 0;
    int op = 0;

    op = open_before(params, p, op);
    if (op == 84)
        return (84);
    for (; p->cmd[size] != NULL; size++);
    size--;
    for (; p->k != size; p->k++) {
        pipe(pipes);
        condi_redi_pipe(params, p, pipes, in);
        close(pipes[1]);
        in = pipes[0];
    }
    p->bulletin = 1;
    condi_redi_pipe(params, p, pipes, in);
    close(in);
    return (11);
}

int check_pipe(params_t *params, char *cmd)
{
    for (int i = 0; params->cmd[i] != NULL; i++) {
        if ((params->cmd[0][0] == '|')) {
            my_putstr("Invalid null command.\n");
            return (11);
        }
        if (check_same_word(params->cmd[i], "|") == 11)
            return (prepare_pipe(params, i));
    }
    return (0);
}
