/*
** EPITECH PROJECT, 2019
** position.h
** File description:
** position.h
*/

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct matrix
{
    float x1;
    float y1;
    float z1;
    float x2;
    float y2;
    float z2;
    float x3;
    float y3;
    float z3;
} i_matrix;

typedef struct vector
{
    float x;
    float y;
} i_vector;

void displayerror(void);
int controlerror(int ac, char **av);
void displayerror();
void print_matrix(i_matrix matrix);
i_matrix translation(int ac, char **av, int i);
i_matrix scaling(int ac, char **av, int i);
i_matrix rotation(int ac, char **av, int i);
i_matrix reflection(int ac, char **av, int i);
i_vector calc_vector(i_matrix matrix, char *flag, i_vector vector);
int controlcara(char *av, int ac);
int error(int ac, char **av);
int resulterror(int nb_arg, int ac);
int nbarg(char **av, int ac);
i_matrix complexe_vector(i_matrix matrix1, i_matrix matrix2);

#endif /* MATRIX_H_ */