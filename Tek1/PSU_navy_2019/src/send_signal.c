/*
** EPITECH PROJECT, 2019
** send_signal.c
** File description:
** send_signal.c
*/

#include "my.h"
#include "../include/navy.h"
#include <signal.h>

char *my_convertbinaire(unsigned int nb)
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
    my_revstr(res);
    return (res);
}