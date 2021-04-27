/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/


#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/position.h"

int controlerror(int ac, char **av)
{
    int i = 1;
    int j = 0;

    if (av[1] == "-h") {
        displayerror();
        return (0);
    }
    else if (ac != 8) {
        displayerror();
        return (84);
    }
    while (i < ac && j == 0) {
        j = is_char(av[i], i);
        i++;
    }
    if (j == 84)
        return (84);
}

int is_char(char *av, int ac)
{
    int i = 0;
    int j = 0;

    while (av[i] != '\0') {
        if (av[i] == '-' || av[i] == '.') {
            if (ac == 7)
                j = -1;
            i++;
        }
        else if (!(av[i] <= '9' && av[i] >= '0'))
            j = -1;
        i++;
    }
    if (j == -1) {
        displayerror();
        return (84);
    }
    return (0);
}
