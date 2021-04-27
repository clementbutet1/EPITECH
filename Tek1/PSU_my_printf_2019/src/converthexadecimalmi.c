/*
** EPITECH PROJECT, 2019
** converthexadecimal.c
** File description:
** converthexadecimal.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include "../include/my.h"

void my_putchar3(char c)
{
    write(1, &c, 1);
}

int my_strlenc(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr3(char *str)
{
    int i = my_strlenc(str) - 1;
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

int my_putstr3(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}

void my_converthexadecimalmi(unsigned int nb)
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
    my_revstr3(res);
    my_putstr3(res);
}

