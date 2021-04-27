/*
** EPITECH PROJECT, 2019
** 104intersection.c
** File description:
** 104intersection.c
*/

#include "include/104insertion.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void findgeometrie(int ac, char **av)
{
    detail_t detail;
    int type = atoi(av[1]);
    detail.px = atof(av[2]);
    detail.py = atof(av[3]);
    detail.pz = atof(av[4]);
    detail.vx = atof(av[5]);
    detail.vy = atof(av[6]);
    detail.vz = atof(av[7]);
    detail.p = atof(av[8]);

    if (type == 1)
        sphere(&detail);
    if (type == 2)
        cylindre(&detail);
    if (type == 3)
        cone(&detail);
}


int main(int ac, char **av)
{
    finderror(ac, av);
    findgeometrie(ac, av);
    return (0);
}
