/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** redirection_funct.c
*/

#include "mysh.h"

void display_redi_error(int fd, char *str)
{
    if (fd == -1) {
        my_putstr(str);
        my_putstr(": No such file or directory.\n)");
    }
}

char **rm_redirection_exe(char **tb, int *d)
{
    int i = 0;
    char **new;

    for (; tb[i] != NULL; i++);
    new = malloc(sizeof(char *) * (i - 1));
    i = 0;
    for (int a = 0; tb[a] != NULL; a++) {
        if (a != *d && a != *d + 1) {
            new[i] = tb[a];
            i++;
        }
        else
            free(tb[a]);
    }
    new[i] = NULL;
    *d = *d - 2;
    free(tb);
    return (new);
}

int error_redirection3(char **tb, int *d, sh_t *sh)
{
    int fd;

    if (tb[*d + 1] == NULL) {
        sh->good_redi = -1;
        if (execute_double_pipe(sh) != 1)
            if (execute_double_pipe(sh) != 1)
                my_putstr_error("Missing name for redirect.\n");
        return (-1);
    }
    fd = open(tb[*d + 1], O_WRONLY | O_CREAT | O_APPEND, 0664);
    if (fd == -1) {
        sh->good_redi = -1;
        if (execute_double_pipe(sh) != 1) {
            if (execute_double_pipe(sh) != 1) {
                my_putstr_error(tb[*d + 1]);
                my_putstr_error(": No such file or directory.\n");
            }
        }
        return (fd);
    }
    return (fd);
}

int error_redirection2(char **tb, int *d, sh_t *sh)
{
    int fd;

    if (tb[*d + 1] == NULL) {
        sh->good_redi = -1;
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("Missing name for redirect.\n");
        return (-1);
    }
    fd = open(tb[*d + 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd == -1) {
        sh->good_redi = -1;
        if (execute_double_pipe(sh) != 1) {
            my_putstr_error(tb[*d + 1]);
            my_putstr_error(": No such file or directory.\n");
        }
        return (fd);
    }
    return (fd);
}

int error_redirection(char **tb, sh_t *sh, int d)
{
    int fd;

    if (tb[d + 1] == NULL) {
        sh->good_redi = -1;
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("Missing name for redirect.\n");
        return (-1);
    }
    if ((fd = open(tb[d + 1], O_RDONLY)) == -1) {
        sh->good_redi = -1;
        if (execute_double_pipe(sh) != 1) {
            my_putstr_error(tb[d + 1]);
            my_putstr_error(": No such file or directory.\n");
        }
        return (fd);
    }
    return (fd);
}