/*
** EPITECH PROJECT, 2019
** 105torus.c
** File description:
** 105torus.c
*/

#include "include/105torus.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void put_in_struct(int ac, char **av, detail_t *detail)
{
    result_t result;

    int type = atoi(av[1]);
    detail->a0 = atoi(av[2]);
    detail->a1 = atoi(av[3]);
    detail->a2 = atoi(av[4]);
    detail->a3 = atoi(av[5]);
    detail->a4 = atoi(av[6]);
    detail->n = atoi(av[7]);
    if (type == 1)
        bisection(detail, &result);
    if (type == 2)
        newton(detail, &result);
    if (type == 3)
        secant(detail, &result);
}

int main(int ac, char **av)
{
    detail_t detail;

    finderror(ac, av);
    put_in_struct(ac, av, &detail);
    return (0);
}
