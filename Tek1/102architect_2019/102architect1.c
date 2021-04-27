/*
** EPITECH PROJECT, 2019
** 102architect1.c
** File description:
** 102architect1.c
*/

#include "include/matrix.h"
#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

i_matrix translation(int ac, char **av, int i)
{
    i_matrix translation = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float Tx = atoi(av[i + 1]);
    float Ty = atoi(av[i + 2]);

    translation.z1 = Tx;
    translation.z2 = Ty;
    return (translation);
}

i_matrix scaling(int ac, char **av, int i)
{
    i_matrix scaling = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float Sx = atoi(av[i + 1]);
    float Sy = atoi(av[i + 2]);

    scaling.x1 = Sx;
    scaling.y2 = Sy;
    return (scaling);
}

i_matrix rotation(int ac, char **av, int i)
{
    i_matrix rotation = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float angle = (atoi(av[i + 1]));

    rotation.y2 = cos((angle) * M_PI / 180);
    rotation.y1 = -sin((angle) * M_PI / 180);
    rotation.x2 = sin((angle) * M_PI / 180);
    rotation.x1 = cos((angle) * M_PI / 180);
    if (rotation.x1 < 0 && rotation.x1 > -0.001)
        rotation.x1 = rotation.x1 * -1;
    if (rotation.y1 < 0 && rotation.y1 > -0.001)
        rotation.y1 = rotation.y1 * -1;
    if (rotation.x2 < 0 && rotation.x2 > -0.001)
        rotation.x2 = rotation.x2 * -1;
    if (rotation.y2 < 0 && rotation.y2 > -0.001)
        rotation.y2 = rotation.y2 * -1;
    return (rotation);
}

i_matrix reflection(int ac, char **av, int i)
{
    i_matrix reflection = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    float angle = (atoi(av[i + 1]) * M_PI) / 180;

    reflection.x1 = cosf(2 * angle);
    reflection.y1 = sinf(2 * angle);
    reflection.x2 = sinf(2 * angle);
    reflection.y2 = -cosf(2 * angle);
    if (reflection.x1 < 0 && reflection.x1 > -0.001)
        reflection.x1 = reflection.x1 * -1;
    if (reflection.y1 < 0 && reflection.y1 > -0.001)
        reflection.y1 = reflection.y1 * -1;
    if (reflection.x2 < 0 && reflection.x2 > -0.001)
        reflection.x2 = reflection.x2 * -1;
    if (reflection.y2 < 0 && reflection.y2 > -0.001)
        reflection.y2 = reflection.y2 * -1;
    return (reflection);
}

i_vector calc_vector(i_matrix matrix, char *flag, i_vector vector)
{
    float c;

    if (flag[0] == '-' && flag[1] == 'z') {
        vector.x = vector.x * matrix.x1;
        vector.y = vector.y * matrix.y2;
    }
    else if (flag[0] == '-' && flag[1] == 't') {
        vector.x = vector.x + matrix.z1;
        vector.y = vector.y + matrix.z2;
    }
    else if (flag[0] == '-' && flag[1] == 'r') {
        c = vector.x;
        vector.x = (vector.x * matrix.x1) - (vector.y * matrix.x2);
        vector.y = (c * matrix.x2) + (vector.y * matrix.y2);
    }
    if (flag[0] == '-' && flag[1] == 's') {
        c = vector.x;
        vector.x = (vector.x * matrix.x1) - (vector.y * matrix.x2);
        vector.y = (c * matrix.x2) + (vector.y * matrix.y2);
    }
    return (vector);
}