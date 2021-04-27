/*
** EPITECH PROJECT, 2019
** 105torus.h
** File description:
** 105torus.h
*/


#ifndef torus_h_
#define torus_h_

typedef struct detail
{
    int opt;
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int n;
}detail_t;

typedef struct result
{
    double x1;
    double x2;
    double x_s;
}result_t;



void displayerror(void);
int finderror(int ac, char **av);

void bisection(detail_t *detail, result_t *result);
void newton(detail_t *detail, result_t *result);
void secant(detail_t *detail, result_t *result);

#endif /* 105torus_h_ */
