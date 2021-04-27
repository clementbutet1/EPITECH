/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_getnbr_char
*/

#include <stdio.h>

int my_getnbr_char(char str)
{
    int nb = 0;

    nb = str - 48;
    return (nb);
}