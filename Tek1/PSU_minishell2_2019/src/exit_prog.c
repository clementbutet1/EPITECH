/*
** EPITECH PROJECT, 2019
** exit_prog.c
** File description:
** exit_prog.c
*/

#include "my.h"
#include"mysh.h"

int check_entry(char *cmd)
{
    int cpt = 0;
    int k = 0;

    for (; cmd[k] != '\0'; k++) {
        if (cmd == NULL || cmd[0] == '\n')
            return (1);
    }
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (check_cara(cmd[i]) == 1)
            return (0);
        if (cmd[i] == ' ')
            cpt++;
    }
    if (cpt == (k - 1)) {
        return (1);
    }
    return (0);
}

void check_exit(char *cmd, params_t *params, char **all_cmd)
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