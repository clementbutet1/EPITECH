/*
** EPITECH PROJECT, 2019
** check_history.c
** File description:
** check_history.c
*/

#include "mysh.h"

void check_print(int type, int cpt, char *str)
{
    int size = 0;

    if (type == 0)
        size = special_strlen(my_getnbr(str));
    if (type == 1)
        size = special_strlen(cpt);
    for (int j = 0; j < 4 - size; j++)
        my_putchar(' ');
    return;
}

void print_history_tab(sh_t *sh)
{
    int i = 0;
    int cpt = 1;

    for (; sh->hist.history[i] != NULL; i++) {
        check_print(1, cpt, NULL);
        my_put_nbr(cpt);
        check_print(0, cpt, sh->hist.h[i]);
        my_putstr(sh->hist.h[i]);
        my_putchar(':');
        my_putstr(sh->hist.min[i]);
        my_putstr("   ");
        my_putstr(sh->hist.history[i]);
        my_putchar('\n');
        cpt++;
    }
}

int check_arg(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else {
            my_putstr("history: Badly formed number.\n");
            return (1);
        }
    }
    return (0);
}

int check_history(char **exe, sh_t *sh, char *name_cmd, int i)
{
    if (my_strcmp(name_cmd, exe[0]) != 0)
        return (0);
    for (; exe[i] != NULL; i++);
    if (i > 3) {
        if (execute_double_pipe(sh) != 1)
            my_putstr_error("history: Too many arguments.\n");
        return (1);
    }
    if (exe[1] != NULL)
        if (check_arg(exe[1]) == 1)
            return (1);
    print_history_tab(sh);
    return (1);
}