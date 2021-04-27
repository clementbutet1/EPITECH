/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr(int nb)
{
    int res;

    if (nb < 10 && nb > 0) {
        my_putchar(nb +48);
    }
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        nb = -nb;
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        res = (nb % 10);
        nb = (nb - res) / 10;
        my_put_nbr(nb);
        my_putchar(48 + res);
    }
}
