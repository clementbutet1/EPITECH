/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** handler_signal.c
*/

#include "mysh.h"

int is_forking(int sig)
{
    static int forking = -1;

    if (sig > 0)
        forking = sig;
    return (forking);
}

void handler_siguint(int i)
{
    i = -1;

    if (is_forking(i) > 1)
        my_putstr("\n");
    else
        (isatty(STDIN_FILENO) == 1) ? my_putstr("\n$> ") : 0;
    return;
}

void handler_sigsegv(void)
{
    my_putstr("Segmentation fault\n");
}

void print_signal(int sig, int status, sh_t *sh)
{
    if (execute_double_pipe(sh) == 1)
        return;
    if (sig == 8 && WCOREDUMP(status))
        my_putstr("Floating exception (core dumped)\n");
    else if (sig == 8)
        my_putstr("Floating exception\n");
    if (WCOREDUMP(status) && sig == 11)
        my_putstr("Segmentation fault (core dumped)\n");
    else if (sig == 11)
        my_putstr("Segmentation fault\n");
}