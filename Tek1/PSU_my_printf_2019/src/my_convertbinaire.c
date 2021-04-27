/*
** EPITECH PROJECT, 2019
** my_convertbinaire.c
** File description:
** my_convertbinaire.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

int my_strlena(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *my_revstr1(char *str)
{
    int i = my_strlena(str) - 1;
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

int my_putstr1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i = i + 1;
    }
}

void my_convertbinaire(unsigned int nb)
{
    int rslt;
    char *res = malloc(sizeof(char) * (nb + 5));
    int i = 0;

    while (nb > 0) {
        rslt = nb % 2;
        nb = nb / 2;
        res[i] = rslt + 48;
        i++;
    }
    my_revstr1(res);
    my_putstr1(res);
}
