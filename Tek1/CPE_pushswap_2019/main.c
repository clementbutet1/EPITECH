/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/pushwap.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void execute(int ac, char **av)
{
    my_putchar('\n');
    return;
}

int checkerror(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] <= 57 && str[i] >= 48 || str[i] == ' '
        || str[i] == '+' || str[i] == '-')) {
            return (0);
        }
        else {
            return (1);
        }
}

int main(int ac, char **av)
{
    if (ac == 2) { 
        my_putchar('\n');
        return (0);
    }
    if (checkerror(av[2]) == 0)
        return (0);
    else
        execute(ac, av);
}