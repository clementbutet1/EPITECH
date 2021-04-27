/*
** EPITECH PROJECT, 2019
** my_prinf2.c
** File description:
** my_printf2.c
*/

#include <stdarg.h>
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

void printbefore(int z, char *str)
{
    while (str[z] != '%') {
        my_putchar(str[z]);
        z++;
    }
}

void printafter(int z, char *str)
{
    while (str[z] != '\0') {
        z++;
    }
    while (str[z] != '%') {
        z--;
    }
    z = z + 2;
    while (str[z] != '\0') {
        my_putchar(str[z]);
        z++;
    }
}
