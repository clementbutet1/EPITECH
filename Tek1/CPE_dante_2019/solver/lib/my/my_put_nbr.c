/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "my.h"
#include <unistd.h>

int nb_special(long nb)
{
    my_put_nbr(nb / 10);
    my_put_nbr(nb % 10);
    return (0);
}

int my_put_nbr(int nb)
{
    int special = 0;
    if (nb == -2147483648) {
        special = 1;
        nb = -214748364;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
    }
    else {
        nb_special(nb);
    }
    if (special == 1) {
        my_putchar(56);
    }
    return (0);
}