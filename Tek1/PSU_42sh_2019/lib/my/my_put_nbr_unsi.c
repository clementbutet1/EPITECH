/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_get_nbr_unsi.c
*/

#include <stdio.h>
#include "my.h"

void my_put_nbr_unsi2(unsigned int nb)
{
    if (nb > 0) {
        my_put_nbr_unsi2(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

void my_put_nbr_unsi(unsigned int nb)
{
    if (nb < 0) {
        nb = nb * -1;
    }
    my_put_nbr_unsi2(nb);
}