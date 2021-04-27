/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr2(int nb)
{
    if (nb >= 0) {
        my_put_nbr2(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar(45);
    }
    my_put_nbr2(nb);
    my_putchar('\n');
}
