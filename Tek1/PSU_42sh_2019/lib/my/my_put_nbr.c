/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_nbr.c
*/

#include "my.h"

void my_put_nbr2(long int nb)
{
    if (nb > 0) {
        my_put_nbr2(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

void my_put_nbr(long int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    my_put_nbr2(nb);
}
