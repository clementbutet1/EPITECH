/*
** EPITECH PROJECT, 2019
** col.c
** File description:
** col.c
*/

#include "mysh.h"

int *check_count_col(char *str, int *tb)
{
    if (str[tb[0]] == '\e') {
        for (tb[1] = tb[0]; str[tb[1]] && str[tb[1]] != 'm'; tb[1]++);
        tb[2] -= (tb[1] - tb[0]);
    }
    return (tb);
}

int cols(char *str)
{
    int *tb = malloc(sizeof(int) * 4);

    for (int i = 0; i <= 3; i++)
        tb[i] = 0;
    for (; str && str[tb[0]]; tb[0]++, tb[2]++) {
        tb = check_count_col(str, tb);
    }
    return (tb[2]);
}