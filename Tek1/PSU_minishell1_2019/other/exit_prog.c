/*
** EPITECH PROJECT, 2019
** exit_prog.c
** File description:
** exit_prog.c
*/

#include "../include/my.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/mysh.h"

void check_exit(char *cmd, params_t *params)
{
    if ((check_entry(cmd) == 1))
        return;
    cmd = clean_str(cmd, params);
    if (cmd[0] == 'e' && cmd[1] == 'x'
    && cmd[2] == 'i' && cmd[3] == 't' && cmd[4] == '\0') {
        my_putstr("exit\n");
        exit (0);
    }
    else
        return;
}

void funct_get_line(char *cmd, params_t *params)
{
    size_t size;

    if ((getline(&cmd, &size, stdin) == -1)) {
        my_putstr("exit\n");
        exit (0);
    } else {
        check_exit(cmd, params);
        check_cmd(cmd, params, size);
    }
}