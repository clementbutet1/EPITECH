/*
** EPITECH PROJECT, 2019
** check_set.c
** File description:
** check_set.c
*/

#include "mysh.h"

void print_tab(char **tb)
{
    for (int i = 0; tb[i] != NULL; i++) {
        my_putstr(tb[i]);
        my_putchar('\n');
    }
    return;
}

int check_set(char **exe, sh_t *sh, char *name_cmd)
{
    if (my_strcmp(name_cmd, exe[0]) != 0)
        return (0);
    if (exe[1] == NULL) {
        print_tab(sh->set);
        return (1);
    }
    return (1);
}