/*
** EPITECH PROJECT, 2019
** my_prinf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void condition3(int z, char *str, va_list ap, ...)
{
    switch (str[z]) {
    case 'p':
        printflagsp(va_arg(ap, int));
        break;
    case 'S':
        printflagss(va_arg(ap, unsigned char *));
        break;
    }
    va_end(ap);
}

void condition2(int z, char *str, va_list ap, ...)
{
    switch (str[z]) {
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'b':
        my_convertbinaire(va_arg(ap, unsigned int));
        break;
    case 'o':
        my_convertoctal(va_arg(ap, unsigned int));
        break;
    case 'x':
        my_converthexadecimalmi(va_arg(ap, unsigned int));
        break;
    case 'X':
        my_converthexadecimalma(va_arg(ap, unsigned int));
        break;
    }
    condition3(z, str, ap);
    va_end(ap);
}

void condition(int z, char *str, va_list ap, ...)
{
    switch (str[z]) {
    case '%':
        my_putchar('%');
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'd':
        my_put_nbr(va_arg(ap, int));
        break;
    case 'c':
        my_putchar(va_arg(ap, int));
        break;
    case 'u':
        my_printflagsu(va_arg(ap, unsigned int));
        break;
    }
    condition2(z, str, ap);
    va_end(ap);
}

void nextcondition(int z, char *str, va_list ap, ...)
{
    if (str[z] == '%')
        my_putchar('%');
    else
        condition(z, str, ap);
}

void my_printf(char *str, ...)
{
    
    int z = 0;
    va_list ap;
    va_start(ap, str);

    for (; str[z] != '\0'; z++) {
        if (str[z] == '%') {
            z++;
            nextcondition(z, str, ap);
        } else
            my_putchar(str[z]);
    }
    va_end(ap);
}
