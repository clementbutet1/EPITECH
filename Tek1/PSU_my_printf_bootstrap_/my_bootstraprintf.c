/*
** EPITECH PROJECT, 2019
** my_bootstraprintf.c
** File description:
** my_bootstraprintf.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int rslt = 0;

    va_start(ap, nb);
    for (int cpt = 0; cpt < nb;) {
        if (i == 0) {
	    cpt++;
            rslt = rslt + va_arg(ap, int);
	}
	if (i == 1) {
	    cpt++;
            rslt = rslt + my_strlen(va_arg(ap, int));
        }
    }
    printf("%d\n", rslt);
    va_end(ap);
}

int main(int ac, char **av)
{
    sum_stdarg(0, 3, 1, 2, 3);
    return (0);
}
      
