/*
** EPITECH PROJECT, 2019
** calcul.c
** File description:
** calcul.c
*/

#include "include/104insertion.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

int calcul_inter2(float x, float y, float z,detail_t *detail)
{
    if (detail->delta > 0) {
        detail->x1 = (-y + sqrt(detail->delta)) / (2 * x);
        detail->x2 = (-y - sqrt(detail->delta)) / (2 * x);
        printf("2 intersection points:\n");
        printf("(%.3f, ", detail->px + detail->x1 * detail->vx);
        printf("%.3f, ", detail->py + detail->x1 * detail->vy);
        printf("%.3f)\n", detail->pz + detail->x1 * detail->vz);
        printf("(%.3f, ", detail->px + detail->x2 * detail->vx);
        printf("%.3f, ", detail->py + detail->x2 * detail->vy);
        printf("%.3f)\n", detail->pz + detail->x2 * detail->vz);
    }
    else if (detail->delta == 0) {
        detail->x1 = -y / (2 * x);
        printf("1 intersection point:\n");
        printf("(%.3f, ", detail->px + detail->x1 * detail->vx);
        printf("%.3f, ", detail->py + detail->x1 * detail->vy);
        printf("%.3f)\n", detail->pz + detail->x1 * detail->vz);
    }
}

int calc_inter(float x, float y, float z, detail_t *detail)
{
    detail->x1 = 0;
    detail->x2 = 0;

    if (x == 0) {
        printf("There is an infinite number of intersection points.\n");
        return (0);
    }
    if (detail->delta < 0) 
        printf ("No intersection point.\n");
    calcul_inter2(x, y, z, detail);
}

void intersection_cone(detail_t *detail)
{
    float x = (detail->vx * detail->vx) + (detail->vy * detail->vy) - (detail->vz * detail->vz) *
    ((tan(detail->p * M_PI/180)) * (tan(detail->p * M_PI/180)));
    float y = (2 * detail->px * detail->vx) + (2 * detail->py * detail->vy) -
    (2 * detail->pz * detail->vz) * ((tan(detail->p * M_PI/180)) * (tan(detail->p * M_PI/180)));
    float z = (detail->px * detail->px) + (detail->py * detail->py) - (detail->pz * detail->pz) *
    ((tan(detail->p * M_PI/180)) * (tan(detail->p * M_PI/180)));
    float deltaa = (y * y) - (4 * x * z);
    detail->delta = deltaa;
    calc_inter(x, y, z, detail);
}