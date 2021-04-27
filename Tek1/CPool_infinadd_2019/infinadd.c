/*
** EPITECH PROJECT, 2019
** infin_add.c
** File description:
** infin_add
*/

#include "my.h"
#include <stdlib.h>

int retenu(char a, char b, int *ret)
{
    int rslt = a - 48 + b - 48 + *ret;

    if (rslt > 9 && (a != '\0' || b != '\0')) {
        *ret = 1;
        return ((rslt % 10) + 48);
    } else {
        *ret = 0;
        return (rslt + 48);
    }
}

char *printrslt(int ret, char *des, char *rslt, int c)
{
    if (ret == 1) {
        my_strcat(rslt, des);
        my_revstr(rslt);
        return (rslt);
    } else {
        rslt[c] = '\0';
        return (my_revstr(rslt));
    }
}

char *addinf(char *av1, char *av2)
{
    int a = my_strlen(av1) - 1;
    int b = my_strlen(av2) - 1;
    char *rslt = malloc(sizeof(char) * (a + b + 5));
    int ret = 0;
    int c = 0;
    char *des = malloc(sizeof(char) * 3);

    des[0] = '1';
    des[1] = '\0';
    for (; a >= 0 || b >= 0; a--, b--, c++) {
        if (a < 0) {
            rslt[c] = retenu(av2[b], '0', &ret);
        } else if (b < 0) {
            rslt[c] = retenu(av1[a], '0', &ret);
        } else
            rslt[c] = retenu(av1[a], av2[b], &ret);
    }
    printrslt(ret, des, rslt, c);
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (my_putstr("./infin_add nbr1 nbr2"));
    else
        my_putstr(addinf(av[1], av[2]));
}
