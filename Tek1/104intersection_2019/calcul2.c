/*
** EPITECH PROJECT, 2019
** calcul2.c
** File description:
** calcul2.c
*/

#include "include/104insertion.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void cone(detail_t *detail)
{
    printf("Cone with a %.f degree angle\n", detail->p);
    printf("Line passing through the point ");
    printf("(%.f, %.f, %.f) ", detail->px, detail->py, detail->pz);
    printf("and parallel to the vector ");
    printf("(%.f, %.f, %.f)\n", detail->vx, detail->vy, detail->vz);
    intersection_cone(detail);
}

void intersection_sphere(detail_t *detail)
{
    float x = (detail->vx * detail->vx) + (detail->vy * detail->vy) + (detail->vz * detail->vz);
    float y = (2 * detail->px * detail->vx) + (2 * detail->py * detail->vy) +
    (2 * detail->pz * detail->vz);
    float z = (detail->px * detail->px) + (detail->py * detail->py) + (detail->pz * detail->pz) - (detail->p * detail->p);
    float deltaa = (y * y) - (4 * x * z);
    detail->delta = deltaa;
    calc_inter(x, y, z, detail);
}

void sphere(detail_t *detail)
{
    printf("Sphere of radius %.f\n", detail->p);
    printf("Line passing through the point ");
    printf("(%.f, %.f, %.f) ", detail->px, detail->py, detail->pz);
    printf("and parallel to the vector ");
    printf("(%.f, %.f, %.f)\n", detail->vx, detail->vy, detail->vz);
    intersection_sphere(detail);
}

void intersection_cylindre(detail_t *detail)
{
    float x = (detail->vx * detail->vx) + (detail->vy * detail->vy);
    float y = (2 * detail->px * detail->vx) + (2 * detail->py * detail->vy);
    float z = (detail->px * detail->px) + (detail->py * detail->py) - (detail->p * detail->p);
    float deltaa = (y * y) - (4 * x * z);
    detail->delta = deltaa;
    calc_inter(x, y, z, detail);
}

void cylindre(detail_t *detail)
{
    printf("Cylinder of radius %.f\n", detail->p);
    printf("Line passing through the point ");
    printf("(%.f, %.f, %.f) ", detail->px, detail->py, detail->pz);
    printf("and parallel to the vector ");
    printf("(%.f, %.f, %.f)\n", detail->vx, detail->vy, detail->vz);
    intersection_cylindre(detail);
}