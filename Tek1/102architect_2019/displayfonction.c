/*
** EPITECH PROJECT, 2019
** displayfonction.c
** File description:
** displayfonction.c
*/

#include "include/matrix.h"
#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void displayerror(void)
{
    printf("USAGE\n");
    printf("    ./102architect x y transfo1 arg11 ");
    printf("[arg12] [transfo2 arg12 [arg22]] ...\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("    x   abscissa of the original point\n");
    printf("    y   ordinate of the original point\n");
    printf("\n");
    printf("    trasnfo arg1 [arg2]\n");
    printf("    -t i j  translation along vector (i, j)\n");
    printf("    -z m n  scaling bu factors m (x-axis) and n (y-axis)\n");
    printf("    -r d    rotation centered in 0 by a d degree angle\n");
    printf("    -s d    reflection over the axis passing through 0 ");
    printf("with an inclination\n");
    printf("            angle of d degree\n");
}

void print_matrix(i_matrix matrix)
{
    printf("%.2f\t%.2f\t%.2f\n", matrix.x1, matrix.y1, matrix.z1);
    printf("%.2f\t%.2f\t%.2f\n", matrix.x2, matrix.y2, matrix.z2);
    printf("%.2f\t%.2f\t%.2f\n", 0.00, 0.00, 1.00);
}

