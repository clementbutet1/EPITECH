/*
** EPITECH PROJECT, 2019
** printflagsp.c
** File description:
** printflagsp.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

int my_strlenf(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr7(char *str)
{
    int i = my_strlenf(str) - 1;
    int b;
    char a;
    int c = 0;

    b = i;
    while (c <= b / 2) {
        a = str[c];
        str[c] = str[i];
        str[i] = a;
        c = c + 1;
        i = i - 1;
    }
    return (str);
}

int my_putstr7(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}

void my_converthexadecimalmi1(int nb)
{
    int rslt;
    char *res = malloc(sizeof(char) * (nb + 5));
    int i = 0;
    char *c = "0123456789abcdef";

    while (nb > 0) {
        rslt = nb % 16;
        nb = nb / 16;
        res[i] = rslt + 48;
        res[i] = c[rslt];
        i++;
    }
    my_revstr7(res);
    my_putstr7(res);
}

void printflagsp(int nb)
{
    my_putchar('0');
    my_putchar('x');
    my_converthexadecimalmi1(nb);
}
