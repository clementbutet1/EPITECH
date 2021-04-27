/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_repeat.c
*/

#include "mysh.h"

int print_repeat(char **exe, sh_t *sh)
{
    int nb;

    for (int i = 0; exe[1][i] != '\0'; i++)
        if (exe[1][i] > '9' || exe[1][i] < '0') {
            if (execute_double_pipe(sh) != 1)
                my_putstr_error("repeat: Badly formed number.\n");
            return (1);
        }
    nb = my_getnbr(exe[1]);
    if (nb < 0)
        return (1);
    for (; nb > 0; nb--)
        check_buffer3(sh, exe + 2);
    return (0);
}

int check_repeat(char **exe, sh_t *sh)
{
    char *repeat = "repeat";
    int i = 0;

    if (my_strcmp(repeat, exe[0]) != 0)
        return (0);
    for (; exe[i] != NULL; i++);
    if (i < 3) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("repeat: Too few arguments.\n");
        return (1);
    }
    print_repeat(exe, sh);
    return (1);
}