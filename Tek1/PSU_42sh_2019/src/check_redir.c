/*
** EPITECH PROJECT, 2019
** check_redir.c
** File description:
** check_redir.c
*/

#include "mysh.h"

char **check_redirection3(char **tb, int *d, sh_t *sh, int cas)
{
    int fd;

    if (cas == -1) {
        fd = error_redirection3(tb, d, sh);
        if (fd == -1)
            return (tb);
        sh->is_redirection = fd;
    }
    else {
        dup2(sh->is_redirection, STDOUT_FILENO);
        close(sh->is_redirection);
        tb = rm_redirection_exe(tb, d);
    }
    return (tb);
}

char **check_redirection2(char **tb, int *d, sh_t *sh, int cas)
{
    int fd;

    if (my_strcmp(tb[*d], ">") == 0) {
        if (cas == -1) {
            fd = error_redirection2(tb, d, sh);
            if (fd == -1)
                return (tb);
            sh->is_redirection = fd;
        }
        else {
            dup2(sh->is_redirection, STDOUT_FILENO);
            close(sh->is_redirection);
            tb = rm_redirection_exe(tb, d);
        }
    }
    else if (my_strcmp(tb[*d], ">>") == 0) {
        tb = check_redirection3(tb, d, sh, cas);
    }
    return (tb);
}

char **check_redirection(char **tb, sh_t *sh, int cas)
{
    for (int d = 0, fd; tb[d] != NULL; d++) {
        if (my_strncmp(tb[d], "<", 1) == 0 && cas != -1) {
            fd = error_redirection(tb, sh, d);
            if (fd == -1)
                return (tb);
            display_redi_error(fd, tb[d] + 1);
            dup2(fd, STDIN_FILENO);
            close(fd);
            tb = rm_redirection_exe(tb, &d);
        }
        else
            tb = check_redirection2(tb, &d, sh, cas);
    }
    return (tb);
}