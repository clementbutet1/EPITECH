/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** 102architect.c
*/

#include "include/matrix.h"
#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

i_matrix complexe_vector(i_matrix matrix1, i_matrix matrix2)
{
    i_matrix new = {0, 1, 0};

    new.x1 = matrix1.x1*matrix2.x1+matrix1.y1*matrix2.y1+matrix1.z1*matrix2.z1;
    new.y1 = matrix1.x2*matrix2.x1+matrix1.y2*matrix2.y1+matrix1.z2*matrix2.z1;
    new.z1 = matrix1.x3*matrix2.x1+matrix1.y3*matrix2.y1+matrix1.z3*matrix2.z1;
    return (new);
}

i_matrix matrix_maker(i_matrix matrix1, i_matrix matrix2)
{
    i_matrix new;

    new.x1 = matrix1.x1*matrix2.x1+matrix1.y1*matrix2.x2+matrix1.z1*matrix2.x3;
    new.y1 = matrix1.x1*matrix2.y1+matrix1.y1*matrix2.y2+matrix1.z1*matrix2.y3;
    new.z1 = matrix1.x1*matrix2.z1+matrix1.y1*matrix2.z2+matrix1.z1*matrix2.z3;
    new.x2 = matrix1.x2*matrix2.x1+matrix1.y2*matrix2.x2+matrix1.z2*matrix2.x3;
    new.y2 = matrix1.x2*matrix2.y1+matrix1.y2*matrix2.y2+matrix1.z2*matrix2.y3;
    new.z2 = matrix1.x2*matrix2.z1+matrix1.y2*matrix2.z2+matrix1.z2*matrix2.z3;
    new.x3 = matrix1.x3*matrix2.x1+matrix1.y3*matrix2.x2+matrix1.z3*matrix2.x3;
    new.y3 = matrix2.x3*matrix2.y1+matrix1.y3*matrix2.y2+matrix1.z3*matrix2.y3;
    new.z3 = matrix1.x3*matrix2.z1+matrix1.y3*matrix2.z2+matrix1.z3*matrix2.z3;
    return (new);
}

i_vector condition(int ac, char **av, i_vector vector)
{
    int i = 3;
    i_matrix matrix1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    i_matrix matrix2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    i_matrix complexe = {atoi(av[1]), atoi(av[2]), 1};
    while (i < ac) {
        if (av[i][0] == '-' && av[i][1] == 'z') {
            printf("Scaling by factors %s and %s\n", av[i + 1], av[i + 2]);
            matrix1 = scaling(ac, av, i);
            matrix1 = matrix_maker(matrix1, matrix2);
            matrix2 = matrix1;
            vector = calc_vector(matrix2, av[i], vector);
        }
        if (av[i][0] == '-' && av[i][1] == 'r') {
            printf("Rotation by a %s degree angle\n", av[i + 1]);
            matrix1 = rotation(ac, av, i);
            matrix1 = matrix_maker(matrix1, matrix2);
            matrix2 = matrix1;
            vector = calc_vector(matrix2, av[i], vector);
        }
        if (av[i][0] == '-' && av[i][1] == 's') {
            printf("Reflection over an axis with an ");
            printf("inclination angle of %s degrees\n", av[i + 1]);
            matrix1 = reflection(ac, av, i);
            matrix1 = matrix_maker(matrix1, matrix2);
            matrix2 = matrix1;
            vector = calc_vector(matrix2, av[i], vector);
        }
        if (av[i][0] == '-' && av[i][1] == 't') {
            printf("Translation along vector (%s, %s)\n", av[i + 1], av[i + 2]);
            matrix1 = translation(ac, av, i);
            matrix1 = matrix_maker(matrix1, matrix2);
            matrix2 = matrix1;
            vector = calc_vector(matrix2, av[i], vector);
        }
        i++;
    }
    print_matrix(matrix1);
    if (i > 6) {
        complexe = complexe_vector(matrix1, complexe);
        vector.x = complexe.x1;
        vector.y = complexe.y1;
        if (vector.x < 0 && vector.x > -0.001)
            vector.x = vector.x * -1;
        if (vector.y < 0 && vector.y > -0.001)
            vector.y = vector.y * -1;
    }
    return (vector);
}

int main(int ac, char **av)
{
    error(ac, av);
    i_vector vector1;
    i_vector vector2;
    int C1 = atoi(av[1]);
    int C2 = atoi(av[2]);
    vector1.x = C1;
    vector1.y = C2;
    vector2 = condition(ac, av, vector1);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n",
    vector1.x, vector1.y, vector2.x, vector2.y);
}