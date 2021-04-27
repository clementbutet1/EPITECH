/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** check_buffer2.c
*/

#include "mysh.h"

int check_buffer2(char **exe, sh_t *sh)
{
    if (check_all_function(exe, sh) == 1)
        return (1);
    if (sh->parenth == 1)
        return (0);
    switch (check_cd(exe, sh)) {
    case 1:
        my_cd(exe, sh, 1);
        break;
    case 2:
        my_cd(exe, sh, 2);
        break;
    case 0:
        return (0);
        break;
    }
    return (1);
}

int check_buffer3(sh_t *sh, char **exe)
{
    sh->pid = 0;
    switch (check_exit(exe, sh)) {
    case 1:
        return (1);
    case 3:
        return (0);
    } if (check_buffer2(exe, sh) == 1) {
        execute_double_and(sh);
        return (0);
    }
    find_path(sh);
    switch (verif_type(exe, sh)) {
    case 0:
        execute_fonction(exe, sh);
        break;
    default:
        return (0);
    }
    return (0);
}

int buffer_pipe2_part2(sh_t *sh, int *fd_in, int *fd_out, int i)
{
    dup2(*fd_in, STDIN_FILENO);
    close(*fd_in);
    dup2(*fd_out, STDOUT_FILENO);
    close(*fd_out);
    if (sh->good_redi != -1)
        sh->exe[i] = check_redirection(sh->exe[i], sh, 0);
    if (sh->good_redi != -1) {
        sh->exe[i] = check_global(sh->exe[i]);
        check_buffer3(sh, sh->exe[i]);
    }
    dup2(*fd_in, 0);
    close(*fd_in);
    return (0);
}

int buffer_pipe2_part1(sh_t *sh, int *fd_in, int i)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return -1;
    dup2(*fd_in, STDIN_FILENO);
    close(*fd_in);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    if (sh->good_redi != -1)
        sh->exe[i] = check_redirection(sh->exe[i], sh, 0);
    if (sh->good_redi != -1) {
        sh->exe[i] = check_global(sh->exe[i]);
        check_buffer3(sh, sh->exe[i]);
    }
    if (sh->spipe.free_or_not == 1)
        free_all(sh->exe[i]);
    *fd_in = pipefd[0];
    return (0);
}