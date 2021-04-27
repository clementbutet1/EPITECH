/*
** EPITECH PROJECT, 2020
** power
** File description:
** is_register
*/

#include "corewar.h"

int is_type(int nb, int byte)
{
    for (int i = 1; i < nb)
        nb = nb << 2;
    nb = nb & 0b11000000;
    if (nb == 0b10000000)
        return 3;
    if (nb == 0b11000000)
        return 2;
    if (nb == 0b01000000)
        return 1;
    return 0;
}