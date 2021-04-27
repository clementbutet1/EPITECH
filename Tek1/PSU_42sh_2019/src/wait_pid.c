/*
** EPITECH PROJECT, 2019
** wait_pid.c
** File description:
** wait_pid.c
*/

#include "mysh.h"

void wait_last_pid(sh_t *sh)
{
    int status;

    if (sh->pid <= 0)
        return;
    if (waitpid(sh->pid, &status, 0) == -1)
        return;
    if (WIFSIGNALED(status)) {
        print_signal(WTERMSIG(status), status, sh);
    }
    if (WIFEXITED(status)) {
        status = WEXITSTATUS(status);
        if (status == 0)
            execute_double_and(sh);
        else
            execute_double_pipe(sh);
    }
}