/*
** EPITECH PROJECT, 2019
** mysh.c
** File description:
** mysh.c
*/

#include "my.h"
#include"mysh.h"

void funct_get_line(char *cmd, params_t *params)
{
    size_t size;

    if ((getline(&cmd, &size, stdin) == -1)) {
        my_putstr("exit\n");
        exit (0);
    } else {
        check_exit(cmd, params, params->cmd);
        check_cmd(cmd, params);
    }
}

void boucl_inf(char **env, params_t *params)
{
    char *cmd = NULL;

    funct_get_line(cmd, params);
    while (11) {
        cmd = NULL;
        my_putstr("$> ");
        funct_get_line(cmd, params);
    }
}