/*
** EPITECH PROJECT, 2019
** printflagsu.c
** File description:
** printflagsu.c
*/

#include <unistd.h>
#include "../include/my.h"

void my_putcharz(char c)
{
    write(1, &c, 1);
}

int my_put_nbrz(int unsigned nb)
{
    int res;

    if (nb < 10 && nb > 0) {
        my_putcharz(nb +48);
    }
    if (nb < 0) {
        nb = nb * -1;
        nb = -nb;
        my_putcharz(nb + 48);
    }
    if (nb > 9) {
        res = (nb % 10);
        nb = (nb - res) / 10;
        my_put_nbrz(nb);
        my_putcharz(48 + res);
    }
}

unsigned int my_printunsint(unsigned int nb)
{
    my_printflagsu(nb / 10);
    my_printflagsu(nb % 10);
}

void my_printflagsu(unsigned int nb)
{
    unsigned int buff;
    unsigned int res;

    if (nb >= 10) {
        my_put_nbrz(nb);
    }
    if (nb < 0) {
        buff = 4294967296 + nb;
        my_printunsint(buff);
    }

    if (nb >= 0) {
        buff = nb;
        buff = buff / 10;
        res = buff % 10;
    }
    if (nb <= 9) {
        my_put_nbrz(nb);
    }
}
