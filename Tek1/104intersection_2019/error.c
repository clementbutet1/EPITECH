/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error.c
*/

#include "include/104insertion.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void displayerror(void)
{
    printf("USAGE\n");
    printf("    ./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n");
    printf("    opt             surface option: 1 for a sphere, 2 ");
    printf("for a cylinder, 3 for a cone\n");
    printf("    (xp, yp, zp)    coordinates of a point by which the ");
    printf("light ray passes through\n");
    printf("    (xv, yv, zv)    coordinates of a vector parallel to ");
    printf("the light ray\n");
    printf("    p               parameter: radius of the sphere, radius ");
    printf("of the cylinder, or\n");
    printf("                    angle formed by the cone and the Z-axis\n");
}

int is_char(char *av, int ac)
{
    int i = 0;
    int j = 0;

    while (av[i] != '\0') {
        if (av[i] == '-' || av[i] == '.') {
            if (ac == 9)
                j = -1;
            i++;
        }
        else if (!(av[i] <= '9' && av[i] >= '0'))
            j = -1;
        i++;
    }
    if (j == -1) {
        displayerror();
        exit (84);
    }
    return (0);
}

void hanldingerror(int ac, char **av)
{
    int i = 1;
    int j = 0;
 
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && atof(av[7]) == 0) {
        displayerror();
        exit (84);
    }
    if (atof(av[8]) < 1 || atof(av[8]) > 360) {
        displayerror();
        exit (84);
    }
    if (av[1][0] == '3' && (atof(av[8]) >= 90) || (atof(av[8]) < 0)) {
        displayerror();
	exit (84);
    }
    while (i < ac && j == 0) {
        j = is_char(av[i], i);
        i++;
    }
    if (j == 84)
        exit (84);
}

int finderror(int ac, char **av)
{
    if (ac != 9) {
        displayerror();
        exit (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        displayerror();
        exit (84);
    }
    if (atof(av[1]) != 3 && atof(av[1]) != 2 && atof(av[1]) != 1) {
        displayerror();
        exit (84);
    }
    hanldingerror(ac, av);
}
