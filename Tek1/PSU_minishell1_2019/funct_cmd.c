/*
** EPITECH PROJECT, 2019
** funct_cmd.c
** File description:
** funct_cmd.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include "include/mysh.h"

char *check_executable(char *cmd, params_t *params, size_t size)
{
    char *rslt = NULL;
    int sz = my_strlen(cmd);

    if (cmd[0] == '.' || cmd[1] == '/') {
        rslt = malloc(sizeof(char *) * (sz + 2));
        rslt = cmd;
        if (check_file_executable(params, rslt, size) == 11)
            return (NULL);
        return (rslt);
    }
    rslt = NULL;
    return (rslt);
}

char *check_good_cmd(char *cmd, params_t *params, size_t size)
{
    char *rslt = NULL;
    int len = my_strlen(params->cmd[0]);

    if (params->envi == NULL || params->path_tab == NULL)
        return (rslt);
    rslt = check_executable(cmd, params, size);
    if (rslt == NULL) {
        rslt = check_access(len, rslt, params);
    } else {
        return (rslt);
    }
}

int execute_cmd(char *cmd, params_t *params, size_t size)
{
    pid_t pid;
    int status;
    int error = 0;

    if ((pid = fork()) == -1) {
        perror("fork");
        return (1);
    }
    if (pid == 0 && params->exe == 0) {
        error = execve(params->good_path, params->cmd, params->envi);
        check_error_excve(cmd, params, size, error);
        exit(0);
    } else
        waitpid(pid, &status, 0);
    check_error_segfault(status);
    return (1);
}

int check_execute_cmd(char *cmd, params_t *params, size_t size)
{
    if (params->envi == NULL) {
        (check_in_the_file(cmd, params, size) == 11);
        return (11);
        if (check_same_word(params->cmd[0], "cd") != 11) {
            my_putstr(cmd);
            my_putstr(": Command not found.\n");
        }
    } else {
        execute_cmd(cmd, params, size);
    }
}

void check_cmd(char *cmd, params_t *params, size_t size)
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
    params->cmd = my_str_tab(cmd, ' ');
    if (find_bulltin(params, cmd, size) == 11)
        return;
    if (find_bulltin(params, cmd, size) == 0) {
        params->good_path = check_good_cmd(cmd, params, size);
        if (check_execute_cmd(cmd, params, size) == 1);
    }
    return;
}