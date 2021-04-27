/*
** EPITECH PROJECT, 2019
** calcul.c
** File description:
** calcul.c
*/

#include "include/105torus.h"
#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

void bisection(detail_t *detail, result_t *result)
{
    double x1 = 0;
    double x2 = 1;
    double norm1;
    double norm2;
    double x;

    if (detail->a0 == 0)
        exit (84);
    for (int i = 1; round(x1 * pow(10, detail->n)) != round(x2 * pow(10, detail->n)); i++) {
        x = (x1 + x2) / 2;
        if (i <= detail->n)
            printf("x = %.*f\n", i, x);
        else
            printf("x = %.*f\n", detail->n, x);
        norm1 = (detail->a4 * pow(x, 4)) + (detail->a3 * pow(x, 3)) +
        (detail->a2 * pow(x, 2)) + (detail->a1 * x) + detail->a0;
        norm2 = (detail->a4 * pow(x1, 4)) + (detail->a3 * pow(x1, 3)) +
        (detail->a2 * pow(x1, 2)) + (detail->a1 * x1) + detail->a0;
        if (norm1 * norm2 < 0)
            x2 = x;
        else
            x1 = x;
    }
}

void newton(detail_t * detail, result_t *result)
{
	double x2 = 0.5;
	double x1 = 0;

	printf("x = %.1g\n", x2);
    for (int count = 0; count < 309; count++) {
        x1 = x2 - ((detail->a4 * pow(x2, 4) + detail->a3 * pow(x2, 3) +
            detail->a2 * pow(x2, 2) + detail->a1 * pow(x2, 1) + detail->a0) /
             ((4 * detail->a4 * pow(x2, 3)) + (3 * detail->a3 * pow(x2, 2)) +
            (2 * detail->a2 * x2) + detail->a1));
        if (round(x2 * pow(10, detail->n)) == round(x1 * pow(10, detail->n)))
            return;
        x2 = x1;
	    printf("x = %.*f\n", detail->n, x1);
    }
}

void calcul_secant(detail_t *detail, result_t *result)
{
    result->x2 = result->x1 - ((detail->a4 * pow(result->x1, 4) + detail->a3 *
    pow(result->x1, 3) +
    detail->a2 * pow(result->x1, 2) + detail->a1 * pow(result->x1, 1) +
    detail->a0)) /
    (((detail->a4 * pow(result->x1, 4) + detail->a3 * pow(result->x1, 3) +
    detail->a2 * pow(result->x1, 2) + detail->a1 * pow(result->x1, 1) +
    detail->a0) -
    (detail->a4 * pow(result->x_s, 4) + detail->a3 * pow(result->x_s, 3) +
    detail->a2 * pow(result->x_s, 2) + detail->a1 * pow(result->x_s, 1) +
    detail->a0)) /
    (result->x1 - result->x_s));
}

void secant(detail_t *detail, result_t *result)
{
    result->x1 = 1;
    result->x2 = 0;
    result->x_s = 0;

    for (int count = 0; count < 309; count++) {
        calcul_secant(detail, result);
        if (round(result->x1 * pow(12, detail->n)) == round(result->x2 * pow(12, detail->n)))
            return;
        result->x_s = result->x1;
        result->x1 = result->x2;
        if (count > 1)
            printf("x = %.*f\n", detail->n, result->x1);
        else
            printf("x = %.*g\n", detail->n, result->x1);
    }
}