/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019_orgenise
** File description:
** cmd_fork.c
*/

#include "my.h"
#include "mysh.h"

int check_execve_option(char *cmd, params_t *params, pid_t pids)
{
    int error = 0;

    if (check_redirection(params, params->cmd) == 84)
        exit (0);
    if (check_redirection(params, params->cmd) == 11) {
        error = execve(params->good_path, params->redi, params->env.envi);
        return (check_error_excve(cmd, params, error));
        exit (0);
    }
}

int execute_execve(char *cmd, params_t *params, pid_t pid, char **all_cmd)
{
    int error = 0;
    int status;

    if (pid == 0) {
        if (check_execve_option(cmd, params, pid) == 11)
            return (11);
        if (params->cmd[0][0] == '/') {
            error = execve(params->cmd[0], params->cmd, params->env.envi);
            return (check_error_excve(cmd, params, error) == 11);
            exit(0);
        }
        error = execve(params->good_path, params->cmd, params->env.envi);
        return (check_error_excve(cmd, params, error));
        exit(0);
    } else
        waitpid(pid, &status, 0);
    check_error_segfault(status);
    return (1);
}

int execute_cmd(char *cmd, params_t *params, char **all_cmd)
{
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        return (11);
    }
    execute_execve(cmd, params, pid, all_cmd);
    return (1);
}