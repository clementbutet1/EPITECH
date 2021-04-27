/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int a;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        a = (nb % 10);
        nb = (nb - a) / 10;
        my_put_nbr(nb);
        my_putchar(48 + a);
    } else
        my_putchar(nb + 48);
}
