/*
** EPITECH PROJECT, 2019
** bulltin.c
** File description:
** bulltin.c
*/

#include "include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "include/mysh.h"

int get_line_of_env(params_t *params)
{
    if (params->envi == NULL)
        return (11);
    if (get_line_pwd(params) == 11)
        return (11);
    if (get_line_old_pwd(params) == 11)
        return (11);
}

int find_bulltin2(params_t *params, char *cmd, size_t size)
{
    if (check_same_word(params->cmd[0], "exit") == 11) {
        check_exit(cmd, params);
        return (11);
    }
    if (check_same_word(params->cmd[0], "unsetenv") == 11) {
        unsetenv_funct(params);
        return (11);
    }
    if (check_same_word(params->cmd[0], "setenv") == 11) {
        setenv_funct(params);
        return (11);
    }
    if (check_same_word(params->cmd[0], "env") == 11) {
        print_env(params);
        return (11);
    }
    return (0);
}

int find_bulltin(params_t *params, char *cmd, size_t size)
{
    get_line_home(params);
    if ((cmd[0] == '.' || cmd[1] == '/')) {
        if (check_directory_executable(params, cmd) == 11)
            return (11);
        else
            return (0);
    }
    if (check_in_the_file(cmd, params, size) == 11)
        return (11);
    if (check_same_word(params->cmd[0], "cd") == 11) {
        check_cd(params, params->cmd[1], cmd);
        return (11);
    }
    if (get_line_of_env(params) == 11)
        return (11);
    if (find_bulltin2(params, cmd, size) == 11)
        return (11);
    return (0);
}