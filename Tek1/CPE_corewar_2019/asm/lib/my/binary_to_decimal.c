/*
** EPITECH PROJECT, 2019
** asm
** File description:
** binary_to_decimal.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int binary_to_decimal(char *str)
{
    int nb = 0;
    str = my_revstr(str);

    for (int a = 0, re = 1; str[a] != '\0'; a++) {
        nb += (str[a] - 48) * re;
        re *= 2;
    }
    return (nb);
}