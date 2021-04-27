/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error.c
*/

#include "my.h"
#include "mysh.h"

int check_error_excve(char *cmd, params_t *params, int error)
{
    if (errno == 8) {
        my_putstr(cmd);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        exit (11);
    } else {
        strerror(error);
        my_putstr(cmd);
        my_putstr(": Command not found.\n");
        exit (11);
    }
    return (0);
}

int check_exit_cara_env(params_t *params, char *str, char *scd_el)
{
    int i = 0;

    if ((str[0] >= '0' && str[0] <= '9')) {
        my_putstr(params->cmd[0]);
        my_putstr(": Variable name must begin with a letter.\n");
        return (11);
    }
    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' &&
        str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            my_putstr(params->cmd[0]);
            my_putstr(": Variable name must contain alphanumeric ");
            my_putstr("characters.\n");
            return (11);
        }
        i++;
    }
    return (0);
}

void print_cmd_not_found(params_t *params, char *cmd)
{
    if (params->path == NULL &&
    (check_same_word(params->cmd[0], "cd") == 11)) {
        my_putstr(cmd);
        my_putstr(": Command not found.\n");
        return;
    }
    return;
}

void check_error_segfault(int status)
{
    if (status == 139) {
        my_putstr("Segmentation fault (core dump)\n");
        return;
    }
    if (status == 11) {
        my_putstr("Segmentation fault\n");
        return;
    }
    if (status == 8) {
        my_putstr("Floating exception\n");
        return;
    }
    if (status == 136) {
        my_putstr("Floating exception (core dump)\n");
        return;
    }
    return;
}

int print_error_directory(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": No such file or directory.\n");
    return (84);
}
