/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** check_echo.c
*/

#include "mysh.h"

void print_echo(char **exe, int type)
{
    int y = 1;

    if (type == 1)
        y = 2;
    for (; exe[y] != NULL; y++) {
        my_putstr(exe[y]);
        if (exe[y + 1] != NULL)
            my_putchar(' ');
    }
    if (type != 1)
        my_putchar('\n');
}

int check_echo(char **exe)
{
    char *echo = "echo";
    int type = 0;

    if (my_strcmp(echo, exe[0]) != 0)
        return (0);
    if (exe[1] == NULL) {
        my_putchar('\n');
        return (1);
    }
    if (my_strcmp("-n", exe[1]) == 0)
        type = 1;
    print_echo(exe, type);
    return (1);
}