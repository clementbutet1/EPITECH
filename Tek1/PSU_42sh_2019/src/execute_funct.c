/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** execute_funct.c
*/

#include "mysh.h"

void execute_fonction2(void)
{
    is_forking(3);
}

void execute_fonction3(char **exe, sh_t *sh)
{
    int d = 0;

    if ((d = execve(exe[0], exe, sh->path.env)) == -1) {
        strerror(d);
        if (errno == 8) {
            if (execute_double_pipe(sh) != 1) {
                my_putstr_error(exe[0]);
                my_putstr_error(": Exec format error. Wrong Architecture.\n");
            }
            exit (0);
        }
    }
}

int execute_fonction(char **exe, sh_t *sh)
{
    sh->pid = fork();

    if (sh->pid == -1) {
        perror("fork");
        return 1;
    }
    else if (sh->pid == 0) {
        execute_fonction3(exe, sh);
    }
    else
        execute_fonction2();
    return (0);
}