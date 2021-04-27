/*
** EPITECH PROJECT, 2019
** operation.c
** File description:  
** operation
*/

#include "my_lib.h"

int soustraction(char *a, char *b)
{
    int rslt;

    rslt = my_getnbr(a) - my_getnbr(b);
    my_put_nbr(rslt);
    return (rslt);
}
int addition(char *a, char *b)
{
    int rslt;

    rslt = my_getnbr(a) + my_getnbr(b);
    my_put_nbr(rslt);
    return (rslt);
}
int division(char *a, char *b)
{
    int rslt;

    rslt = my_getnbr(a) / my_getnbr(b);
    my_put_nbr(rslt);
    return (rslt);
}
int modulo(char *a, char *b)
{
    int rslt;

    rslt = my_getnbr(a) % my_getnbr(b);
    my_put_nbr(rslt);
    return (rslt);
}
