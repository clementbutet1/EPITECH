/*
** EPITECH PROJECT, 2019
** open_redi.c
** File description:
** open_redi.c
*/

#include "my.h"
#include "mysh.h"

int redi_simple_right_pipe(params_t *params, int i, pipe_t *p, int k)
{
    int op = 0;

    if ((p->cmd[k][i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    if ((op = open(p->cmd[k][i + 1], O_RDWR | O_TRUNC | O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        return (print_error_directory(params->cmd[i + 1]));
    p->cmd[k][i] = NULL;
    return (op);
}

int redi_double_right_pipe(params_t *params, int i, pipe_t *p, int k)
{
    int op = 0;

    if ((p->cmd[k][i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    if ((op = open(p->cmd[k][i + 1], O_RDWR | O_APPEND | O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        return (print_error_directory(p->cmd[k][i + 1]));
    p->cmd[k][i] = NULL;
    return (op);
}

int redi_simple_left_pipe(params_t *params, int i, pipe_t *p, int k)
{
    int op = 0;

    if ((p->cmd[k][i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    if ((open(p->cmd[k][i + 1], O_RDONLY) == -1))
        return (print_error_directory(p->cmd[k][i + 1]));
    if (params->cmd[i + 1])
        op = open(params->cmd[i + 1], O_RDONLY, 0);
    p->cmd[k][i] = NULL;
    return (op);
}

int open_pipe(params_t *params, pipe_t *p, int k)
{
    for (int i = 0; p->cmd[k][i] != NULL; i++) {
        if (check_same_word(p->cmd[k][i], ">") == 11)
            return (redi_simple_right_pipe(params, i, p, k));
        if (check_same_word(p->cmd[k][i], "<") == 11)
            return (redi_simple_left_pipe(params, i, p, k));
        if (check_same_word(p->cmd[k][i], ">>") == 11)
            return (redi_double_right_pipe(params, i, p, k));
    }
    return (1);
}