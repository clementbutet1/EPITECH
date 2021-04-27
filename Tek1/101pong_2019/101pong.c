/*
** EPITECH PROJECT, 2019
** 101pong.c
** File description:
** 101pong.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include/position.h"

void velocity_vector(i_position pos_in, i_position pos_fin)
{
    double vx = pos_fin.x - pos_in.x;
    double vy = pos_fin.y - pos_in.y;
    double vz = pos_fin.z - pos_in.z;

    printf("The velocity vector of the ball is:\n");
    printf("(%.2f", vx);
    printf(", %.2f", vy);
    printf(", %.2f", vz);
    printf(")%s\n");
}

void time_n(i_position pos_in, i_position pos_fin, char *n)
{
    int t = my_getnbr(n);
    double vx = pos_fin.x - pos_in.x;
    double vy = pos_fin.y - pos_in.y;
    double vz = pos_fin.z - pos_in.z;
    double xn = pos_fin.x + (vx * t);
    double yn = pos_fin.y + (vy * t);
    double zn = pos_fin.z + (vz * t);

    printf("At time t + ");
    printf("%d", t);
    printf(", ball coordinates will be:\n");
    printf("(%.2f", xn);
    printf(", %.2f", yn);
    printf(", %.2f", zn);
    printf(")%s\n");
}

void angle(i_position pos_in, i_position pos_fin, char *n)
{
    int t = my_getnbr(n);
    double vx = pos_fin.x - pos_in.x;
    double vy = pos_fin.y - pos_in.y;
    double vz = pos_fin.z - pos_in.z;
    double len = ((vx * vx) + (vy * vy) + (vz * vz));
    double hyp = vz / sqrt(len);
    double angle = (180 * (acos(hyp) - (M_PI/2))/M_PI);
    double zn = pos_fin.z + (vz * t);

    if (angle < 0)
        angle = angle * -1;
    if (vz != 0 && ((-pos_fin.z)/ vz) >= 0 && pos_fin.x != 0) {
        printf("%s\n", "The incidence angle is:");
        printf("%.2f degrees\n", angle);
    }
    else if (zn >= 0 && pos_fin.z >= 0 || zn < 0 && pos_fin.z < 0)
        printf("The ball won't reach the paddle.\n");
    else
        printf("The ball won't reach the paddle.\n");
}

void displayerror(void)
{
    my_putstr("USAGE");
    my_putchar('\n');
    my_putstr("    ./101pong x0 y0 z0 x1 y1 z1 n");
    my_putchar('\n');
    my_putchar('\n');
    printf("%s\n", "DESCRIPTION");
    my_putstr("    x0  ball abscissa at time t - 1");
    my_putchar('\n');
    my_putstr("    y0  ball ordinate at time t - 1");
    my_putchar('\n');
    my_putstr("    z0  ball altitude at time t - 1");
    my_putchar('\n');
    my_putstr("    x1  ball abscissa at time t");
    my_putchar('\n');
    my_putstr("    y1  ball ordinate at time t");
    my_putchar('\n');
    printf("%s\n", "    z1  ball altitude at time t");
    my_putstr("    n   time shift ");
    my_putstr("(greater than or equal to zero, integer)");
    my_putchar('\n');
}

int main(int ac, char **av)
{
    i_position pos_in;
    i_position pos_fin;

    if (controlerror(ac, av) == 84) {
        return (84);
    if (my_getnbr(av[7]) == 0) {
        displayerror();
        return (84);
    }
    } else {
        pos_in.x = strtof(av[1], NULL);
        pos_in.y = strtof(av[2], NULL);
        pos_in.z = strtof(av[3], NULL);
        pos_fin.x = strtof(av[4], NULL);
        pos_fin.y = strtof(av[5], NULL);
        pos_fin.z = strtof(av[6], NULL);
        velocity_vector(pos_in, pos_fin);
        time_n(pos_in, pos_fin, av[7]);
        angle(pos_in, pos_fin, av[7]);
    }
    return (0);
}
