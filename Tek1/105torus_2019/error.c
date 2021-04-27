/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "include/105torus.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int check_nbr(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        i++;
    }
    if (str[i] != '\n' && str[i] != '\0')
        return (1);
    return (0);
}

void displayerror(void)
{
    printf("USAGE\n");
    printf("    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n");
    printf("    opt       method option:\n");
    printf("                  1 for the bisection method\n");
    printf("                  2 for Newton’s method\n");
    printf("                  3 for the secant method\n");
    printf("    a[0-4]    coefficients of the equation\n");
    printf("    n         precision (the application of the polynomial to the solution should\n");
    printf("              be smaller than 10ˆ-n)\n");
}

void finderror_part2(int ac, char **av)
{
    if (atof(av[1]) != 3 && atof(av[1]) != 2 && atof(av[1]) != 1) {
        displayerror();
        exit (84);
    }
    if (atof(av[7]) <= 0) {
        displayerror();
        exit (84);
    }
    for (int i = 1; i < 8; i++) {
        if (check_nbr(av[i]) == 1) {
            displayerror();
            exit (84);
        }
    }
}

int finderror(int ac, char **av)
{
    if (ac == 1) {
        displayerror();
        exit (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        displayerror();
        exit (84);
    }
    if (ac != 8) {
        displayerror();
        exit (84);
    }
    finderror_part2(ac, av);
}
