/*
** EPITECH PROJECT, 2019
** boucl_inf.c
** File description:
** boucl_inf.c
*/

#include "mysh.h"

int boucl_inf(sh_t *sh, time_t now)
{
    while (1) {
        sh->buffer = NULL;
        sh->s = 0;
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("$> ");
        if (getline(&sh->buffer, &sh->s, stdin) == -1) {
            (isatty(STDIN_FILENO) == 1) ? my_putstr("exit\n") : 0;
            exit (0);
        }
        if (check_buffer(sh, now) == 1)
            return (sh->exit);
        free(sh->buffer);
    }
}