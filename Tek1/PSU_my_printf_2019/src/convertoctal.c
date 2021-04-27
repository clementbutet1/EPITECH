/*
** EPITECH PROJECT, 2019
** convertoctal.c
** File description:
** convertoctal.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

int my_strlenb(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr2(char *str)
{
    int i = my_strlenb(str) - 1;
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

int my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}

void my_convertoctal(unsigned int nb)
{
    int rslt;
    char *res = malloc(sizeof(char) * (nb + 5));
    int i = 0;

    while (nb > 0) {
        rslt = nb % 8;
        nb = nb / 8;
        res[i] = rslt + 48;
        i++;
    }
    my_revstr2(res);
    my_putstr2(res);
}
