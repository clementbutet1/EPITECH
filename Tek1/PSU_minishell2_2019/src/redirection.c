/*
** EPITECH PROJECT, 2019
** redirection.c
** File description:
** redirection.c
*/

#include "my.h"
#include "mysh.h"

int redi_simple_right(params_t *params, int i, char **cmd)
{
    int fd = 0;

    if ((cmd[i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    if ((fd = open(cmd[i + 1], O_RDWR | O_TRUNC | O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        return (print_error_directory(params->cmd[i + 1]));
    dup2(fd, 1);
    cmd[i] = NULL;
    close(fd);
    params->redi = cmd;
    return (11);
}

int redi_double_right(params_t *params, int i, char **cmd)
{
    int fd = 0;

    if ((cmd[i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    if ((fd = open(cmd[i + 1], O_RDWR | O_APPEND | O_CREAT, S_IRUSR |
        S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        return (print_error_directory(cmd[i + 1]));
    dup2(fd, 1);
    cmd[i] = NULL;
    close(fd);
    params->redi = cmd;
    return (11);
}

int redi_simple_left(params_t *params, int i, char **cmd)
{
    int fd = 0;

    if ((cmd[i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    if ((open(cmd[i + 1], O_RDONLY) == -1))
        return (print_error_directory(cmd[i + 1]));
    if (params->cmd[i + 1]) {
        int fd = open(params->cmd[i + 1], O_RDONLY, 0);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
    cmd[i] = NULL;
    params->redi = cmd;
    return (11);
}

int redi_double_left(params_t *params, int i, char **cmd)
{
    int fd = 0;
    int pid = 0;
    int tmp[2];

    if ((cmd[i + 1] == NULL)) {
        my_putstr("Missing name for redirect.\n");
        return (84);
    }
    pipe(tmp);
    dup2(tmp[0], 0);
    close(tmp[1]);
    cmd[i] = NULL;
    params->redi = cmd;
    return (11);
}

int check_redirection(params_t *params, char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        if ((cmd[0][0] == '>' || cmd[0][0] == '<' ||
        (check_same_word(cmd[0], "<<") == 11) ||
        (check_same_word(cmd[0], ">>") == 11))) {
            my_putstr("Invalid null command.\n");
            return (84);
        }
        if (check_same_word(cmd[i], ">") == 11)
            return (redi_simple_right(params, i, cmd));
        if (check_same_word(cmd[i], "<") == 11)
            return (redi_simple_left(params, i, cmd));
        if (check_same_word(cmd[i], ">>") == 11)
            return (redi_double_right(params, i, cmd));
        if (check_same_word(cmd[i], "<<") == 11)
            return (redi_double_left(params, i, cmd));
    }
    return (0);
}