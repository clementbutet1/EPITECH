/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "include/matrix.h"
#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int resulterror(int nb_arg, int ac)
{
    if (nb_arg != ac) {
        displayerror();
        exit(84);
    }
    return (0);
}

int nbarg(char **av, int ac)
{
    int i = 0;
    int nb_arg = 3;

    while (i < ac) {
        if (av[i][1] == 'z') {
            nb_arg = nb_arg + 3;
        }
        if (av[i][1] == 'r') {
            nb_arg = nb_arg + 2;
        }
        if (av[i][1] == 't') {
            nb_arg = nb_arg + 3;
        }
        if (av[i][1] == 's') {
            nb_arg = nb_arg + 2;
        }
        i++;
    }
    resulterror(nb_arg, ac);
}

int ctrl(int ac, int j)
{
    if (ac == 7)
        j = -1;
    return (j);
}

int controlcara(char *av, int ac)
{
    int i = 1;
    int j = 0;

    while (av[i] != '\0') {
        if (av[i] == '-' || av[i] == '.' || av[i] == 't'
        || av[i] == 'r' || av[i] == 'z' || av[i] == 's') {
            ctrl(ac, j);
            i++;
        }
        else if (!(av[i] <= 57 && av[i] >= 48))
            j = - 1;
        i++;
    }
    if (j == -1) {
        displayerror();
        exit(84);
    }
    return (0);
}

int error(int ac, char **av)
{
    int i = 1;
    int j = 0;

    if (ac < 5) {
        displayerror();
        exit(84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        displayerror();
        return (0);
    }
    while (i < ac && j == 0) {
        j = controlcara(av[i], i);
        i++;
    }
    if (j == 84)
        exit(84);
    nbarg(av, ac);
}